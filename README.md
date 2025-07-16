# pipex
This is a 42 project which aims to simulate how a pipe works in a shell.

To compile:
`make`

To compile the bonus:
`make bonus`

To run:
`./pipex input_file "command1" ... "commandN" output_file`

or (here_doc)
`./pipex here_doc LIMITER "command1" ... "commandN" output_file`
___

In this project we must create different sub-processes which will execute each of the commands passed as arguments, and create pipes that will allow communication between those sub-processes.

In order to mimic the functioning of a pipe in the shell, it's important to understand how exactly the shell operates when we pipe two or more commands/programs together.
This is an explanation of the bonus part of the project, since it encompasses the mandatory part as well.

## Important notions:
A command takes an input and returns an output. The commands we use in the shell wait for input through the Standard Input (stdin **fd** = 0), output the result to the Standard Output (stdout **fd** = 1) and any errors to Standard Error (stderr **fd** = 2).

A pipe is a undirectional communication channel, that gets written to on one end (write-end fd[1]) and is read on the other end (fd[0]). Something important to note is that a pipe works more like a shipping container in practice, the data isn't constantly flowing from one end to the other, it is stored there after getting written, up until it's read, after which it is gone. It is actually a buffer that exists on the kernel level, so if a pipe gets more data written into it than it has capacity to store, it will block until the data gets read on the other end, after which it will allow more data to be written. (This will prove handy later on, when addressing how data is transferred from one sub-process to another).

A fork is a way to create a new process (child) from the calling process (parent). The child process is identical in most ways to the parent process, it is a copy of all of it's memory, running in separate memory spaces. Among some things, they have different PID (process ID).

Why do we need to fork for each command? Why can't we do it for all but one, and have the parent process execute the last command, that way the program will return the appropriate exit status, as is required to mimic the shell pipe?
- When we create a sub-process, we need to have the parent wait (`wait()` or `waitpid()`) for the child to finish execution, otherwise the parent might reach the end of the program and finish, before the child does.
- When the parent is waiting, it doesn't do anything else. So what happens if the amount of data that is being passed through the pipe, from the child to the parent, is bigger than the pipe buffer?

Well, what happens is **nothing**... The program will stall, because the parent is waiting for the child to finish execution and the child is waiting for the pipe to be read so it can send the rest of the data it wants to send (remember that the pipe will block when it's full, until the data is read on the read-end).

That's why we need to have the two sub-processes executing (writing and reading simultaneously), while the parent waits for them both. This is important and is easy to miss without tests that send a lot of data through the pipe).

### How the shell processes pipes (more or less)
In a very concise way:
- The shell parses the input, identifying input/output filenames, redirection and pipe operators, as well as the commands.
- Within the shell, somewhere, there is a loop where:
  - A pipe is created for each pair of commands, in order to allow for inter-process communication (IPC). (2 commands -> 1 pipe, 3 commands -> 2 pipes, N commands -> N-1 pipes). This pipe is always created in the parent process (this case, the shell), so that both child processes can access the **fds** necessary to send/receive data.
  - The first fork occurs, creating a child process. It is only within this child process that redirection occurs! This is will be very important, in order to mimic the shell pipe completely. It's explained why further below. [^1]
  - Within a child process, the following steps take place, depending on which of the child processes it is:
    - If it's the first child process, input comes from the input file, so it is necessary to open it, and handle errors accordingly, output goes to the pipe.
    - If it's the last child process, input comes from the pipe, output goes to the output file, so it is necessary to open/create it, and handle errors accordingly.
    - If it's neither, input comes from the pipe connecting to the previous sub-process and output goes to the pipe connecting to the next sub-process.
All the while, **fds** that are not needed are closed and redirection occurs.
    - Finally the commands are executed, replacing in it's entirety the child process, receiving and sending data from the redirected **fds**.
  - On each iteration of the loop, the shell closes the all the **fds** it doesn't need. It saves one **fd**, which is the read-end of the pipe from the current iteration, to pass on to the next sub-process (it needs to get it's input).
- The shell waits on all child processes to finish execution. It writes the output to the requested **fd**.

In order to mimic this behaviour, we'll have to adapt a bit, but it should all flow in the same manner.

### How I mimic'd the pipe
1. Parsing

First, we need to parse the input.

In our program, we don't have a pipe or redirection operators, we know that the 1st argument is the input file, the 2nd argument is the first command, the 3rd argument is the second command, and so on, and that the last argument is the output file.

These are all shifted one position forward if the 1st argument is "here_doc".

Since we know what we're expecting, the parsing is straight-forward, we only need to check to see wether it's a here_doc or not, but I'll leave this to end.

2. "Pipeline" loop

Since we have an undetermined number of commands, it's important to be able to adapt.

We first declare a variable **prev_read_fd** and initialize it to -1.

We will loop *number of commands* times.

If it's not the last command, we will create a pipe.

Then we fork, creating a child process.

In this child process:
- If it's the first command, we get the input from the input file. We open the file, and use dup2 to make the Standard Input that the command receives come from the **fd** of the open input file. (This makes it so that the STDIN **fd** (0) points to the input file (e.g.: 3)) In order to avoid pipe leaks, it's important to always close **fd** that you don't intend on using, so we close the **fd** that originally pointed to the input file (3).
- If it's not the first command, the **prev_read_fd** will have been changed to the last commands' pipe read **fd**. So we use dup2 to redirect the output of the pipe to the input of the command. Always close unused **fd** (prev_read_fd). 
- If it's the last command, open the output file (once again, it's very important to do this inside the child process[^1]). dup2 the STDOUT to the output file **fd**. Close the original output file **fd**.
- If not the last command, dup2 the STDOUT to the write-end of the pipe created this iteration. Close original write-end of the pipe. Close the read-end of the pipe.
- Finally, execute the command.
(As it's very poorly explained above, in the two first steps we handle the input for the command, and in the last two the output)

Back to the parent process, but still within the loop:
- We close the prev_read_fd, it won't be needed anymore;
- If it's not the last command, we close the write-end of the pipe, and set the **prev_read_fd** to the read-end of the pipe;
- If it's the last command, we do an extra little thing where we save the **pid** of the last child process, so that we can return the exit status from the parent program (It's what the shell does)

Still in the parent process, but outside the loop, after having forked child processes for all commands:
- We loop for the number of commands, and call the `waitpid()` function on loop, which will wait for all processes to finish execution, and if the pid of the process that has finished executing matches the pid of the last command process, we'll save it so we can return it (even though the last process is, well, the last process to be forked, it won't necessarily be the last to execute... I think, that's why I do this)
- I then return from the main function, and the return value is the value that was saved from the last command sub-process.

I did this way and was able to replicate the way the shell functions in every way, I could remember (output, errors, run time, and no leaks)

[^1] The reason why we need to open the input and output files inside the child process is twofold:
- One is that, if the open fails, the sub-process finishes, but this doesn't mean that the whole sequence of piped commands fails, it just means that the pipe that is expecting output from the failed command process, will be empty on the other end, and the following programs can continue executing, which is what the shell does;
- Second is that the shell sets the variable $? to the exit status of the last command, and to do this, we need to be able to possibly get the failed exit status of the last command.

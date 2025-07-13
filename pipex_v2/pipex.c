#include "pipex.h"

void	init_pipe(t_pipex *px, int i);
int		init_fork(t_pipex *px, int i);
void	pipeline(t_pipex *px);


int	main(int ac, char **av, char **ep)
{
	t_pipex	*px;

	px = init_px(ac, av, ep);
	pipeline(px);
	exit_success(px);
}

void	pipeline(t_pipex *px)
{
	int	in_fd;
	int	out_fd;
	int	prev_read_fd;
	int	i;
	int	pid;

	px->debug = open("./log_debug", O_CREAT | O_WRONLY, 00664);
	if (px->debug == -1)
		exit_fail(px, "Couldn't create log file");
	
	in_fd = ft_open(px, 'i');
	if (in_fd == -1)
		exit_fail(px, "File doesn't exist");
	out_fd = ft_open(px, 'o'); // open/create out_file
	if (out_fd == -1)
		exit_fail(px, "Couldn't create output file");
	prev_read_fd = -1;
	i = 0;
	while (i < px->nr_cmds)
	{
		init_pipe(px, i);
		pid = init_fork(px, i);
		if (pid == 0) // Child
		{
			// Input
			if (i == 0) // First command
			{
				if (px->debug)
					dprintf(px->debug, "[C%d] INPUT:\n", i);
				ft_dup2(in_fd, STDIN_FILENO, px, i);
			}
			else // Command that receives/reads from pipe
			{
				if (px->debug)
					dprintf(px->debug, "[C%d] INPUT:\n", i);
				ft_dup2(prev_read_fd, STDIN_FILENO, px, i);
			}
			// Output
			if (i == px->nr_cmds - 1) // Last command
			{
				if (px->debug)
					dprintf(px->debug, "[C%d] OUTPUT:\n", i);
				ft_dup2(out_fd, STDOUT_FILENO, px, i);
			}
			else // Command that sends/writes to pipe
			{
				if (px->debug)
					dprintf(px->debug, "[C%d] OUTPUT:\n", i);
				ft_dup2(px->fd[1], STDOUT_FILENO, px, i);
			}
			if (i > 0)
				ft_close(prev_read_fd, px, i, 'c');
			if (i < px->nr_cmds - 1)
			{
				ft_close(px->fd[0], px, i, 'c');
				ft_close(px->fd[1], px, i, 'c');
			}
			ft_close(in_fd, px, i, 'c');
			ft_close(out_fd, px, i, 'c');
			execve(px->cmds[i][0], px->cmds[i], NULL);
			exit_fail(px, "execve failed");
		}
		if (i < px->nr_cmds - 1)
		{
			if (i > 0)
			{
				ft_close(prev_read_fd, px, i, 'p');
				if (px->debug)
					dprintf(px->debug, "[P] prev_read_fd is now: %d\n", prev_read_fd);
			}
			prev_read_fd = px->fd[0];
			ft_close(px->fd[1], px, i, 'p');
			if (px->debug)
				dprintf(px->debug, "[P] prev_read_fd is now: %d\n", prev_read_fd);
		}
		i++;
	}
	ft_close(in_fd, px, i, 'p');
	ft_close(out_fd, px, i, 'p');
	i = -1;
	while (++i < px->nr_cmds)
		wait(NULL);
}

void	init_pipe(t_pipex *px, int i)
{
	if (i < px->nr_cmds - 1)
	{
		if (pipe(px->fd) == -1)
			exit_fail(px, "pipe");
		if (px->debug)
			dprintf(px->debug, "[P] Init pipe %d:\n\tfd[0]: %d\n\tfd[1]: %d\n", i, px->fd[0], px->fd[1]);
	}
}

int	init_fork(t_pipex *px, int i)
{
	int	pid;

	if (px->debug)
		dprintf(px->debug, "[P] Forking child %d\n", i);
	pid = fork();
	if (pid == -1)
		exit_fail(px, "fork");
	return (pid);
}

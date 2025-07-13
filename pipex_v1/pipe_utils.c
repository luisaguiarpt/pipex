#include "pipex.h"

void	not_first_cmd(int prev_read_fd)
{
	dup2(prev_read_fd, STDIN_FILENO); // stdin fd now points to pipe read
	//close(prev_read_fd);
}

void	first_cmd(int prev_read_fd, t_pipex *px)
{
	close(px->fd[0]);
	prev_read_fd = open(px->in_path, O_RDONLY);
	dup2(prev_read_fd, STDIN_FILENO); // stdin fd now points to pipe read
	//close(prev_read_fd);
}

void	not_last_cmd(t_pipex *px)
{
	close(px->fd[0]); // close read-end
	dup2(px->fd[1], STDOUT_FILENO); // stdout fd now points to pipe write
	close(px->fd[1]); // close write-end to avoid leaks
}

void	last_cmd(t_pipex *px)
{
	int	file_write_fd;

	close(px->fd[0]);
	file_write_fd = open(px->out_path, O_CREAT | O_WRONLY, 00664);
	//ft_printf("write fd: %d\n", file_write_fd);
	dup2(file_write_fd, STDOUT_FILENO);
	close(file_write_fd);
}

void	exec_cmd(t_pipex *px, int prev_read_fd, int i)
{
	if (prev_read_fd != -1)
		not_first_cmd(prev_read_fd);
	if (prev_read_fd == -1)
		first_cmd(prev_read_fd, px);
	if (i < px->nr_cmds - 1)
		not_last_cmd(px);
	if (i == px->nr_cmds - 1)
		last_cmd(px);
	execve(px->cmds[i][0], px->cmds[i], NULL);
	exit_fail(px, "Failed to execute command");
}

void	pipeline(t_pipex *px)
{
	int	prev_read_fd;
	int	pid;
	int	i;

	prev_read_fd = -1;
	i = 0;
	while (i < px->nr_cmds)
	{
		init_pipe(px, i);
		pid = init_fork(px);
		if (pid == 0)
			exec_cmd(px, prev_read_fd, i);
		if (prev_read_fd != -1)
			close(prev_read_fd);
		if (i < px->nr_cmds - 1)
		{
			close(px->fd[1]);
			prev_read_fd = px->fd[0];
		}
		i++;
	}
	i = -1;
	while (++i < px->nr_cmds)
		wait(NULL);
}

//void	pipeline(t_pipex *px)
//{
//	int	prev_read_fd;
//	int	pid;
//	int	i;
//
//	prev_read_fd = -1;
//	i = 0;
//	while (i < px->nr_cmds)
//	{
//		init_pipe(px, i);
//		pid = init_fork(px);
//		if (pid == 0) // Child
//		{
//			// Not the first command - we want to read from pipe
//			if (prev_read_fd != -1)
//			{
//				dup2(prev_read_fd, STDIN_FILENO); // stdin fd now points to pipe read
//				close(prev_read_fd);
//			}
//			// First command - we want to read from input fd
//			if (prev_read_fd == -1)
//			{
//				prev_read_fd = open(px->in_path, O_RDONLY);
//				dup2(prev_read_fd, STDIN_FILENO); // stdin fd now points to pipe read
//				//close(prev_read_fd);
//			}
//			// Not the last cmd - we want to write into the pipe
//			if (i < px->nr_cmds - 1)
//			{
//				close(px->fd[0]); // close read-end
//				dup2(px->fd[1], STDOUT_FILENO); // stdout fd now points to pipe write
//				close(px->fd[1]); // close write-end to avoid leaks
//			}
//			if (i == px->nr_cmds - 1)
//			{
//				close(px->fd[0]);
//				w2file_fd = open(px->out_path, O_CREAT | O_WRONLY, 00664);
//				ft_printf("write fd: %d\n", w2file_fd);
//				dup2(w2file_fd, STDOUT_FILENO);
//				close(w2file_fd);
//			}
//			execve(px->cmds[i][0], px->cmds[i], NULL);
//			exit_fail(px, "Failed to execute command");
//		}
//		if (prev_read_fd != -1)
//			close(prev_read_fd);
//		if (i < px->nr_cmds - 1)
//		{
//			close(px->fd[1]); // parent doesn't write
//			prev_read_fd = px->fd[0];
//		}
//		i++;
//	}
//	i = -1;
//	while (++i < px->nr_cmds)
//		wait(NULL);
//}

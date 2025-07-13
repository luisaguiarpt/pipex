#include "pipex.h"

void	init_pipe(t_pipex *px, int i);
int	init_fork(t_pipex *px);
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
	int	prev_read_fd;
	int	in_fd;
	int	out_fd;
	int	pid;
	int	i;
	int	j;

	in_fd = open(px->in_path, O_RDONLY);
	out_fd = open(px->out_path, O_CREAT | O_WRONLY, 00664);
	prev_read_fd = -1;
	i = 0;
	while (i < px->nr_cmds)
	{
		init_pipe(px, i);
		pid = init_fork(px);
		if (pid == 0) // Child
		{
			if (i == 0)
				dup2(in_fd, STDIN_FILENO);
			else
				dup2(prev_read_fd, STDIN_FILENO);
			if (i == px->nr_cmds - 1)
				dup2(out_fd, STDOUT_FILENO);
			else
				dup2(px->fd[1], STDOUT_FILENO);
			if (i > 0)
				close(prev_read_fd);
			if (i < px->nr_cmds - 1)
			{
				close(px->fd[0]);
				close(px->fd[1]);
			}
			close(in_fd);
			close(out_fd);
			execve(px->cmds[i][0], px->cmds[i], px->ep);
			exit_fail(px, "Failed to execute command");
		}
		if (i > 0)
			close(prev_read_fd);
		if (i < px->nr_cmds - 1)
		{
			prev_read_fd = px->fd[0];
			close(px->fd[1]);
		}
		i++;
	}
	j = -1;
	while (++j < px->nr_cmds)
		wait(NULL);
}

void	init_pipe(t_pipex *px, int i)
{
	if (i < px->nr_cmds - 1)
		if (pipe(px->fd) == -1)
			exit_fail(px, "pipe");
}

int	init_fork(t_pipex *px)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		exit_fail(px, "fork");
	return (pid);
}

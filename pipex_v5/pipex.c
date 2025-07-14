#include "pipex.h"

int	main(int ac, char **av, char **ep)
{
	int	fd[2];
	int	pid1;
	int	pid2;
	int	status2;

	if (ac < 5)
		exit_fail(1);
	if (pipe(fd) == -1)
		exit_fail(2);
	pid1 = fork();
	if (pid1 == -1)
		exit_fail(3);
	if (pid1 == 0)
		cmd1(av, ep, fd);
	close(fd[1]);
	pid2 = fork();
	if (pid2 == -1)
		exit_fail(3);
	if (pid2 == 0)
		cmd2(av, ep, fd);
	close(fd[0]);
	waitpid(pid1, &status2, 0);
	waitpid(pid2, &status2, 0);
	if (WIFEXITED(status2))
		return (WEXITSTATUS(status2));
}

void	cmd1(char **av, char **ep, int fd[2])
{
	int		in_fd;
	char	*in_path;

	if (!ft_strlen(av[2]))
		exit_fail(6);
	in_path = ft_strjoin2(ft_strjoin(get_ep("PWD=", ep), "/"), av[1], 0);
	in_fd = open(in_path, O_RDONLY);
	free(in_path);
	if (in_fd == -1)
		exit_fail(4);
	close(fd[0]);
	dup2(in_fd, STDIN_FILENO);
	close(in_fd);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	exec_cmd(av[2], ep);
}

void	cmd2(char **av, char **ep, int fd[2])
{
	int		out_fd;
	char	*out_path;

	if (!ft_strlen(av[3]))
		exit_fail(6);
	out_path = ft_strjoin2(ft_strjoin(get_ep("PWD=", ep), "/"), av[4], 0);
	out_fd = open(out_path, O_WRONLY | O_CREAT | O_TRUNC, 00664);
	free(out_path);
	if (out_fd == -1)
		exit_fail(4);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(out_fd, STDOUT_FILENO);
	close(out_fd);
	exec_cmd(av[3], ep);
}

void	exec_cmd(char *av_cmd, char **ep)
{
	char	*cmd_path;
	char	**cmds;

	cmd_path = get_path(av_cmd, ep);
	cmds = ft_split(av_cmd, ' ');
	if (execve(cmd_path, cmds, ep) == -1)
	{
		ft_free_tab(cmds);
		free(cmd_path);
		exit_fail(6);
	}
}

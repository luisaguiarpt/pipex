#include "pipex_bonus.h"

int	main(int ac, char **av, char **ep)
{
	int		i;
	int		status;
	t_pipex	px;

	if (ac < 5)
		ft_exit(1);
	if (!ft_strcmp(av[1], "here_doc"))
		px.here_d = 1;
	else
		px.here_d = 0;
	px.nr_cmds = ac - 3 - px.here_d;
	i = -1;
	while (++i < px.nr_cmds)
		pipeline(px, av, ep, i);
	i = -1;
	while (++i < px.nr_cmds)
		wait(&status); 
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
}

void	pipeline(t_pipex px, char **av, char **ep, int i)
{
	int	pid;

	if (i < px.nr_cmds - 1)
		if (pipe(px.fd) == -1)
			ft_exit(2);
	pid = fork();
	if (pid == -1)
		ft_exit(3);
	else if (!pid)
	{
		if (i == 0)
			first_cmd(px, av, ep, i);
		else if (i == px.nr_cmds - 1)
			last_cmd(px, av, ep, i);
		else
			middle_cmd(px, av, ep, i);
	}
	else
	{
		if (i == 0)
			close(px.fd[1]);
		else if (i == px.nr_cmds - 1)
			close(px.fd[0]);
	}
}

void	middle_cmd(t_pipex px, char **av, char **ep, int i)
{
	dup2(px.fd[0], STDIN_FILENO);
	close(px.fd[0]);
	dup2(px.fd[1], STDOUT_FILENO);
	close(px.fd[1]);
	px.prev_fd = px.fd[0];
	exec_cmd(px, av, ep, i);
}

void	first_cmd(t_pipex px, char **av, char **ep, int i)
{
	int		in_fd;

	in_fd = get_input(px, av, ep);
	px.prev_fd = px.fd[0];
	close(px.fd[0]);
	dup2(in_fd, STDIN_FILENO);
	close(in_fd);
	dup2(px.fd[1], STDOUT_FILENO);
	close(px.fd[1]);
	exec_cmd(px, av, ep, i);
}

void	last_cmd(t_pipex px, char **av, char **ep, int i) 
{
	int		out_fd;

	out_fd = get_output(px, av, ep);
	close(px.fd[1]);
	dup2(px.fd[0], STDIN_FILENO);
	close(px.fd[0]);
	dup2(out_fd, STDOUT_FILENO);
	close(out_fd);
	exec_cmd(px, av, ep, i);
}

void	exec_cmd(t_pipex px, char **av, char **ep, int i)
{
	char	*cmd_path;
	char	**cmds;
	int		cmd_i;

	cmd_i = i + 2 + px.here_d;
	cmd_path = get_path(av[cmd_i], ep);
	cmds = ft_split(av[cmd_i], ' ');
	if (execve(cmd_path, cmds, ep) == -1)
	{
		ft_free_tab(cmds);
		free(cmd_path);
		ft_exit(7);
	}
}

int	get_output(t_pipex px, char **av, char **ep)
{
	char	*out_path;
	int		out_fd;

	out_path = ft_strjoin2(ft_strjoin(get_ep("PWD=", ep), "/"), av[px.nr_cmds + 2 + px.here_d], 0);
	if (px.here_d)
		out_fd = open(out_path, O_CREAT | O_WRONLY | O_APPEND, 00664);
	else
		out_fd = open(out_path, O_CREAT | O_WRONLY | O_TRUNC, 00664);
	if (out_fd == -1)
		ft_exit(6);
	return (out_fd);
}

int	get_input(t_pipex px, char **av, char **ep)
{
	int		in_fd;
	char	*in_path;

	if (px.here_d)
		return (here_doc(av));
	else
	{
		in_path = ft_strjoin2(ft_strjoin(get_ep("PWD=", ep), "/"), av[1], 0);
		in_fd = open(in_path, O_RDONLY);
		free(in_path);
		if (in_fd == -1)
			ft_exit(5);
	}
	return (in_fd);
}

int	here_doc(char **av)
{
	int		tmp_fd;
	char	*line;

	tmp_fd = open(".heredoc_tmp", O_CREAT | O_RDWR | O_APPEND, 00664);
	if (tmp_fd < 0)
		ft_exit(4);
	line = get_next_line(STDIN_FILENO);
	while (line && !ft_strcmp(line, av[2]))
	{
		ft_putendl_fd(line, tmp_fd);
		line = get_next_line(STDIN_FILENO);
	}
	return (tmp_fd);
}

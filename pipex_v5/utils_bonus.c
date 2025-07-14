#include "pipex_bonus.h"

char	*get_path(char *av_cmd, char **ep)
{
	int		i;
	char	**cmd;
	char	**paths;
	char	*cmd_path;

	cmd = ft_split(av_cmd, ' ');
	paths = ft_split(get_ep("PATH=", ep), ':');
	i = -1;
	while (paths[++i])
	{
		cmd_path = ft_strjoin2(ft_strjoin(paths[i], "/"), cmd[0], 0);
		if (access(cmd_path, X_OK) == 0)
		{
			ft_free_tab(cmd);
			ft_free_tab(paths);
			return (cmd_path);
		}
		free(cmd_path);
	}
	ft_free_tab(cmd);
	ft_free_tab(paths);
	ft_exit(8);
	return (NULL);
}

char	*get_ep(char *var, char **ep)
{
	int	i;
	int	var_size;

	var_size = ft_strlen(var);
	i = 0;
	while (ep[i])
	{
		if (!ft_strncmp(var, ep[i], var_size))
			return (&ep[i][var_size]);
		i++;
	}
	return (0);
}

int	get_output(t_pipex *px, char **av, char **ep)
{
	char	*out_path;
	int		out_fd;

	out_path = ft_strjoin2(ft_strjoin(get_ep("PWD=", ep), "/"),
			av[px->nr_cmds + 2 + px->here_d], 0);
	if (px->here_d)
		out_fd = open(out_path, O_CREAT | O_WRONLY | O_APPEND, 00664);
	else
		out_fd = open(out_path, O_CREAT | O_WRONLY | O_TRUNC, 00664);
	free(out_path);
	if (out_fd == -1)
		ft_exit(6);
	return (out_fd);
}

int	get_input(t_pipex *px, char **av, char **ep)
{
	int		in_fd;
	char	*in_path;

	if (px->here_d)
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
	ft_putstr_fd("> ", 1);
	line = get_next_line(STDIN_FILENO);
	while (line && ft_strncmp(line, av[2], ft_strlen(line) - 1))
	{
		ft_putstr_fd("> ", 1);
		ft_putstr_fd(line, tmp_fd);
		line = get_next_line(STDIN_FILENO);
	}
	close(tmp_fd);
	tmp_fd = open(".heredoc_tmp", O_RDONLY);
	return (tmp_fd);
}

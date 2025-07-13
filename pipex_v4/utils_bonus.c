#include "pipex_bonus.h"

void	ft_exit(int	err)
{
	if (err == 1)
		perror("Usage: ./pipex <here_doc LIMITER/file1> cmd1 cmd2 file2");
	if (err == 2)
		perror("Pipe");
	if (err == 3)
		perror("Fork");
	if (err == 4)
		perror("here_doc");
	if (err == 5)
		perror("Input file");
	if (err == 6)
		perror("Output file");
	if (err == 7)
		perror("Couldn't execute command");
	if (err == 8)
		perror("Couldn't find command");
	exit(1);
}

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

#include "pipex.h"

void	exit_fail(int err)
{
	if (err == 1)
		perror("Usage: ./pipex input_file cmd1 cmd2 output_file\n");
	else if (err == 2)
		perror("Pipe");
	else if (err == 3)
		perror("Fork");
	else if (err == 4)
		perror("Invalid input file name");
	else if (err == 5)
		perror("Output file doesn't exist and couldn't be created");
	else if (err == 6)
		perror("Execution failed");
	else if (err == 7)
		perror("Couldn't find command");
	else if (err == 8)
		perror("No permissions for input file");
	if (err == 7)
		exit(127);
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
	exit_fail(7);
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

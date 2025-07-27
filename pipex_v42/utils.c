/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 19:12:30 by ldias-da          #+#    #+#             */
/*   Updated: 2025/07/27 14:55:59 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_fail(t_codes err)
{
	if (err == ERR_USAGE)
		ft_putstr_fd("Usage: ./pipex input_file cmd1 cmd2 output_file\n", 2);
	else if (err == ERR_PIPE)
		ft_putstr_fd("Pipe failed\n", 2);
	else if (err == ERR_FORK)
		ft_putstr_fd("Fork failed\n", 2);
	else if (err == ERR_INPUT)
		ft_putstr_fd("Invalid input file\n", 2);
	else if (err == ERR_OUTPUT)
		ft_putstr_fd("Output file doesn't exist/couldn't be created\n", 2);
	else if (err == EXEC_FAIL)
		ft_putstr_fd("Execution failed\n", 2);
	else if (err == CMD_NA)
		ft_putstr_fd("Couldn't find command\n", 2);
	if (err == CMD_NA)
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
	exit_fail(CMD_NA);
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

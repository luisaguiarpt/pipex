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

static void	put_error(char *str, char *error_str, int flag);

void	exit_fail(t_codes err, char *str)
{
	if (err == ERR_USAGE)
		ft_putstr_fd("Usage: ./pipex input_file cmd1 cmd2 output_file\n", 2);
	else if (err == ERR_PIPE)
		put_error("pipe fail", strerror(errno), 1);
	else if (err == ERR_FORK)
		put_error("fork fail", strerror(errno), 1);
	else if (err == ERR_INPUT || err == ERR_OUTPUT)
		put_error(str, strerror(errno), 0);
	else if (err == EXEC_FAIL)
		ft_putstr_fd("Execution failed\n", 2);
	else if (err == CMD_NA)
		put_error(str, strerror(errno), 1);
	if (err == CMD_NA)
		exit(127);
	exit(1);
}

static void	put_error(char *str, char *error_str, int flag)
{
	if (flag == 0)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(error_str, 2);
		ft_putstr_fd("\n", 2);
	}
	else if (flag == 1)
	{
		ft_putstr_fd("'", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("'", 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd("command not found\n", 2);
	}
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
	exit_fail(CMD_NA, NULL);
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

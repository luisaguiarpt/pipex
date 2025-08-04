/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 19:11:57 by ldias-da          #+#    #+#             */
/*   Updated: 2025/07/27 17:07:36 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	put_error(char *str, char *error_str, int flag);

void	ft_exit(t_error_code err, char *str)
{
	if (err == USE_ERR)
	{
		ft_putstr_fd("Usage:\n\t./pipex file cmd1 ... cmdN file2\n", 2);
		ft_putstr_fd("or, using here doc:\n", 2);
		ft_putstr_fd("\t./pipex heredoc LIMITER cmd1 ... cmdN file2\n", 2);
	}
	if (err == PIPE_ERR)
		put_error("pipe fail", strerror(errno), 1);
	if (err == FORK_ERR)
		put_error("fork fail", strerror(errno), 1);
	if (err == HEREDOC_ERR)
		put_error("here_doc fail", strerror(errno), 1);
	if (err == INPUT_ERR || err == OUTPUT_ERR)
		put_error(str, strerror(errno), 0);
	if (err == CMDEXEC_ERR)
		ft_putstr_fd("Couldn't execute command\n", 2);
	if (err == CMD_NA)
		put_error(str, strerror(errno), 1);
	if (err == CMD_NA)
		exit(127);
	exit(1);
}

/**
 *	flag for the output format:
 *		0 -> input/output file error
 *		1 -> command not found
 */
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

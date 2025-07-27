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

void	ft_exit(t_error_code err)
{
	if (err == USE_ERR)
		ft_putstr_fd("Usage: ./pipex <heredoc LIM/file1> cmd1 cmd2 file2\n", 2);
	if (err == PIPE_ERR)
		ft_putstr_fd("Pipe fail\n", 2);
	if (err == FORK_ERR)
		ft_putstr_fd("Fork fail\n", 2);
	if (err == HEREDOC_ERR)
		ft_putstr_fd("here_doc fail\n", 2);
	if (err == INPUT_ERR)
		ft_putstr_fd("Input file fail\n", 2);
	if (err == OUTPUT_ERR)
		ft_putstr_fd("Output file fail\n", 2);
	if (err == CMDEXEC_ERR)
		ft_putstr_fd("Couldn't execute command\n", 2);
	if (err == CMD_NA)
		ft_putstr_fd("Couldn't find command\n", 2);
	if (err == CMD_NA)
		exit(127);
	exit(1);
}

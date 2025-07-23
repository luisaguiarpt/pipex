/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 19:11:57 by ldias-da          #+#    #+#             */
/*   Updated: 2025/07/23 19:29:02 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_exit(t_error_code err)
{
	if (err == USE_ERR)
		perror("Usage: ./pipex <here_doc LIMITER/file1> cmd1 cmd2 file2");
	if (err == PIPE_ERR)
		perror("Pipe fail");
	if (err == FORK_ERR)
		perror("Fork fail");
	if (err == HEREDOC_ERR)
		perror("here_doc fail");
	if (err == INPUT_ERR)
		perror("Input file fail");
	if (err == OUTPUT_ERR)
		perror("Output file fail");
	if (err == CMDEXEC_ERR)
		perror("Couldn't execute command");
	if (err == CMDLOC_ERR)
		perror("Couldn't find command");
	if (err == CMDLOC_ERR)
		exit(127);
	exit(1);
}

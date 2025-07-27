/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 19:12:52 by ldias-da          #+#    #+#             */
/*   Updated: 2025/07/27 12:54:41 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft/libft/libft.h"
# include "libft/get_next_line/get_next_line.h"
# include "libft/ft_printf/includes/ft_printf.h"
# include <unistd.h>
# include <fcntl.h>	
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	int	nr_cmds;
	int	here_d;
	int	fd[2];
	int	prev_fd;
	int	out_fd;
	int	in_fd;
	int	last_pid;
	int	last_status;
}				t_pipex;

typedef enum e_error_code
{
	USE_ERR,
	PIPE_ERR,
	FORK_ERR,
	HEREDOC_ERR,
	INPUT_ERR,
	OUTPUT_ERR,
	CMDEXEC_ERR,
	CMD_NA
}				t_error_code;

// Main functions - pipex_bonus.c
void	pipeline(t_pipex *px, char **av, char **ep, int i);
void	init_pipex(t_pipex *px, int ac, char **av);
void	exec_cmd(t_pipex *px, char **av, char **ep, int i);
void	exec_child(t_pipex *px, char **av, char **ep, int i);

// Utility function - utils_bonus.c
int		get_input(t_pipex *px, char **av, char **ep);
int		get_output(t_pipex *px, char **av, char **ep);
int		here_doc(char **av);
char	*get_ep(char *var, char **ep);
char	*get_path(char *av_cmd, char **ep);

// Exit function - exit.c
void	ft_exit(t_error_code err);

#endif

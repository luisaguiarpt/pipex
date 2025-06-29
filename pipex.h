#ifndef PIPEX_H
# define PIPEX_H

#include "libft/libft/libft.h"
#include "libft/ft_printf/includes/ft_printf.h"
#include <unistd.h>		// pipe, fork, execve, dup, read, close, access
#include <fcntl.h>		// open
#include <stdlib.h>		// malloc, exit
#include <stdio.h>		// perror
#include <sys/wait.h>	// wait

typedef struct s_pipex
{
	char	**files;
	char	***cmds;
}				t_pipex;

// Parse - parse.c
void	av_parse(int ac, char **av, t_pipex *px);

// Init - init.c
t_pipex	*init_px(int ac, char **av, char **ep);

// Free - free.c
void	free_cmds(t_pipex *px);
void	free_files(t_pipex *px);

// Exit - exit.c
void	exit_fail_pre(char *reason);
void	exit_fail(t_pipex *px, char *reason);

#endif

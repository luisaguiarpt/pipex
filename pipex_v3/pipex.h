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
	int		fd[2];
	char	**files;
	char	***cmds;
	char	**ep;
	int		nr_cmds;
	char	*in_path;
	char	*out_path;
	char	*pwd;
	char	*content;
	char	*shell;
}				t_pipex;

// Parse - parse.c
void	av_parse(int ac, char **av, t_pipex *px);
void	ev_parse(char **ep, t_pipex *px);

// Init - init.c
t_pipex	*init_px(int ac, char **av, char **ep);

// Free - free.c
void	free_cmds(t_pipex *px);
void	free_path(t_pipex *px);
void	free_envp(t_pipex *px);

// Exit - exit.c
void	exit_fail_pre(char *reason);
void	exit_fail(t_pipex *px, char *reason);
void	exit_success(t_pipex *px);

#endif

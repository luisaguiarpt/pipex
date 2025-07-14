#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft/libft.h"
# include "libft/ft_printf/includes/ft_printf.h"
# include <unistd.h>		// pipe, fork, execve, dup, read, close, access
# include <fcntl.h>		// open
# include <stdlib.h>		// malloc, exit
# include <stdio.h>		// perror
# include <sys/wait.h>	// wait

typedef struct s_pipex
{
	int	in_fd;
	int	out_fd;
}				t_pipex;

void	exec_cmd(char *av_cmd, char **ep);
void	cmd1(char **av, char **ep, int fd[2]);
void	cmd2(char **av, char **ep, int fd[2]);
char	*get_path(char *av_cmd, char **ep);
char	*get_ep(char *var, char **ep);
void	exit_fail(int err);

#endif

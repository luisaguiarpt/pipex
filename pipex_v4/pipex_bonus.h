#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft/libft/libft.h"
# include "libft/get_next_line/get_next_line.h"
# include "libft/ft_printf/includes/ft_printf.h"
# include <unistd.h>	// pipe, fork, execve, dup, read, close, access
# include <fcntl.h>		// open
# include <stdlib.h>	// malloc, exit
# include <stdio.h>		// perror
# include <sys/wait.h>	// wait

typedef struct	s_pipex
{
	int	nr_cmds;
	int	here_d;
	int	fd[2];
	int	prev_fd;
}				t_pipex;

void	pipeline(t_pipex px, char **av, char **ep, int i);
void	exec_cmd(t_pipex px, char **av, char **ep, int i);
void	middle_cmd(t_pipex px, char **ac, char **ep, int i);
void	first_cmd(t_pipex px, char **av, char **ep, int i);
void	last_cmd(t_pipex px, char **av, char **ep, int i);
int		get_input(t_pipex px, char **av, char **ep);
int		get_output(t_pipex px, char **av, char **ep);
int		here_doc(char **av);
char	*get_ep(char *var, char **ep);
char	*get_path(char *av_cmd, char **ep);
void	ft_exit(int	err);

#endif

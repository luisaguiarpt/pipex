#include "pipex.h"

void	exit_fail_pre(char *reason)
{
	perror(reason);
	exit(EXIT_FAILURE);
}

void	exit_fail(t_pipex *px, char *reason)
{
	perror(reason);
	free_cmds(px);
	free_files(px);
	exit(EXIT_FAILURE);
}

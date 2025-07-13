#include "pipex.h"

void	exit_fail_pre(char *reason)
{
	perror(reason);
	exit(1);
}

void	exit_fail(t_pipex *px, char *reason)
{
	perror(reason);
	free_cmds(px);
	free_path(px);
	free(px->pwd);
	free(px);
	exit(1);
}

void	exit_success(t_pipex *px)
{
	free_cmds(px);
	free_path(px);
	free(px->pwd);
	free(px);
}

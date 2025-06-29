#include "pipex.h"

t_pipex	*init_px(int ac, char **av, char **ep)
{
	t_pipex	*px;

	px = ft_calloc(1, sizeof(t_pipex));
	if (!px)
		exit_fail_pre("pipex");
	px->cmds = NULL;
	px->files = NULL;
	av_parse(ac, av, px);
	(void)ep;
	//ev_parse(ep, px);
	return (px);
}

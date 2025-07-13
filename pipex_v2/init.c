#include "pipex.h"

t_pipex	*init_px(int ac, char **av, char **ep)
{
	t_pipex	*px;

	px = ft_calloc(1, sizeof(t_pipex));
	if (!px)
		exit_fail_pre("pipex");
	px->nr_cmds = ac - 3;
	px->cmds = NULL;
	px->files = NULL;
	px->in_path = NULL;
	px->out_path = NULL;
	px->debug = 1;
	ev_parse(ep, px);
	av_parse(ac, av, px);
	return (px);
}

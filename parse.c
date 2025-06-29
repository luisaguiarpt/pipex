#include "pipex.h"

static int	av_check(int ac, char **av);

void	av_parse(int ac, char **av, t_pipex *px)
{
	int	i;
	int	nr_cmds;

	nr_cmds = ac - 3;
	if (av_check(ac, av))
		exit_fail(px, "parse");
	px->cmds = ft_calloc(nr_cmds + 1, sizeof(char **));
	if (!px->cmds)
		exit_fail(px, "malloc: cmds");
	i = -1;
	while (++i < ac - 3)
		px->cmds[i] = ft_split(av[i + 2], ' ');
}

static int	av_check(int ac, char **av)
{
	(void)av;
	if (ac < 5)
		return (1);
	return (0);
}

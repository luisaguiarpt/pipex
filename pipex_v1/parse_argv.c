#include "pipex.h"

static int	av_check(int ac, char **av);
static void	get_cmds(int ac, char **av, t_pipex *px);
static void	get_paths(int ac, char **av, t_pipex *px);

void	av_parse(int ac, char **av, t_pipex *px)
{
	if (av_check(ac, av))
		exit_fail(px, "parse");
	px->cmds = ft_calloc(px->nr_cmds + 1, sizeof(char **));
	if (!px->cmds)
		exit_fail(px, "malloc: cmds");
	get_cmds(ac, av, px);
	get_paths(ac, av, px);
}

static void	get_cmds(int ac, char **av, t_pipex *px)
{
	int		i;
	char	*tmp;

	i = -1;
	while (++i < ac - 3)
	{
		px->cmds[i] = ft_split(av[i + 2], ' ');
		if (!px->cmds)
			exit_fail(px, "split");
		tmp = px->cmds[i][0];
		px->cmds[i][0] = ft_strjoin("/bin/", px->cmds[i][0]);
		free(tmp);
	}
}

static void	get_paths(int ac, char **av, t_pipex *px)
{
	char	*tmp;

	tmp = ft_strdup(av[1]);
	px->in_path = ft_strjoin(px->pwd, tmp);
	if (!px->in_path)
		exit_fail(px, "malloc: path");
	free(tmp);
	tmp = ft_strdup(av[ac - 1]);
	px->out_path = ft_strjoin(px->pwd, tmp);
	if (!px->out_path)
		exit_fail(px, "malloc: path");
	free(tmp);
}

static int	av_check(int ac, char **av)
{
	(void)av;
	if (ac < 5)
		return (1);
	return (0);
}

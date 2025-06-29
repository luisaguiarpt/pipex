#include "pipex.h"

int	main(int ac, char **av, char **ep)
{
	t_pipex	*px;

	px = init_px(ac, av, ep);
	for (int i = 0; i < ac - 3; i++)
	{
		ft_printf("Cmd%d:\n", i);
		for (int j = 0; px->cmds[i][j]; j++)
		{
			ft_printf("%d: %s\n", j, px->cmds[i][j]);
		}
	}
}

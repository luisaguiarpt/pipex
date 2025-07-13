#include "pipex.h"

void	free_cmds(t_pipex *px)
{
	int	i;
	int	j;

	if (px->cmds)
	{
		i = 0;
		while (px->cmds[i])
		{
			j = 0;
			while (px->cmds[i][j])
				free(px->cmds[i][j++]);
			free(px->cmds[i][j++]);
			free(px->cmds[i++]);
		}
		free(px->cmds);
	}
}

void	free_path(t_pipex *px)
{
	if (px->in_path)
		free(px->in_path);
	if (px->out_path)
		free(px->out_path);
}

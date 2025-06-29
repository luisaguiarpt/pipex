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

void	free_files(t_pipex *px)
{
	int	i;

	if (px->files)
	{
		i = 0;
		while (px->files[i])
			free(px->files[i]);
		free(px->files[i]);
		free(px->files);
	}
}

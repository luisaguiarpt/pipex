#include "pipex.h"

static char	*get_ep(char *var, char **ep);

void	ev_parse(char **ep, t_pipex *px)
{
	px->shell = get_ep("SHELL=", ep);
	px->pwd = ft_strjoin(get_ep("PWD=", ep), "/");
}

static char	*get_ep(char *var, char **ep)
{
	int	i;
	int	var_size;

	var_size = ft_strlen(var);
	i = 0;
	while (ep[i])
	{
		if (!ft_strncmp(var, ep[i], var_size))
			return (&ep[i][var_size]); 
		i++;
	}
	return (0);
}

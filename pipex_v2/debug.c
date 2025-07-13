#include "pipex.h"

int	ft_open(t_pipex *px, char in_out)
{
	int	fd;

	if (in_out == 'i')
	{
		fd = open(px->in_path, O_RDONLY);
		if (px->debug)
			dprintf(px->debug, "[P] opened: in_fd: %d\n", fd);
	}
	else
	{
		fd = open(px->out_path, O_CREAT | O_WRONLY, 00664);
		if (px->debug)
			dprintf(px->debug, "[P] opened: out_fd: %d\n", fd);
	}
	return (fd);
}

void	ft_dup2(int old_fd, int new_fd, t_pipex *px, int i)
{
	if (px->debug)
		dprintf(px->debug, "[C%d] Redirected %d to %d\n", i, new_fd, old_fd);
	dup2(old_fd, new_fd);
}

void	ft_close(int fd, t_pipex *px, int i, char pc)
{
	if (px->debug)
	{
		if (pc == 'c')
			dprintf(px->debug, "[C%d] closed: fd = %d\n", i, fd);
		if (pc == 'p')
			dprintf(px->debug, "[P] closed: fd = %d\n", fd);
	}
	close(fd);
}

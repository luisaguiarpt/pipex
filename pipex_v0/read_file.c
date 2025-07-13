#include "pipex.h"

char	*read_file(const char *pathname, t_pipex *px)
{
	char	*content;
	char	*line;
	int		fd;

	if (!access(pathname, R_OK))
		exit_fail(px, "can't access file");
	fd = open(pathname, O_RONLY);
	if (!fd)
		exit_fail(px, "can't open file");
	line = get_next_line(fd);
	while (line)
	{
		content = ft_strjoin2(file, line);
		free(line);
		line = get_next_line(fd);
	}
	return (content);
}

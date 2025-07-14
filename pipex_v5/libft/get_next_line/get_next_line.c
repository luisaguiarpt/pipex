/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:11:27 by ldias-da          #+#    #+#             */
/*   Updated: 2025/05/22 12:18:59 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static char	buf[4096][BUFFER_SIZE + 1];
	char		*line;
	ssize_t		n;

	line = NULL;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	line = add_line(line, buf[fd]);
	while (!ft_strchr(line, '\n'))
	{
		n = read(fd, buf[fd], BUFFER_SIZE);
		if (n < 0 || !buf[fd][0])
		{
			shift_buf(buf[fd]);
			free(line);
			return (NULL);
		}
		if (n == 0)
			break ;
		if (n < BUFFER_SIZE)
			buf[fd][n] = 0;
		line = add_line(line, buf[fd]);
	}
	shift_buf(buf[fd]);
	return (line);
}
/*
#include <stdio.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	char	*line;

	(void)ac;
	int	fd = open(av[1], O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	close(fd);
}
*/

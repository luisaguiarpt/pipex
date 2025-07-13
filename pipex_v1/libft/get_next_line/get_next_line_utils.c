/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:01:13 by ldias-da          #+#    #+#             */
/*   Updated: 2025/05/22 12:19:08 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*add_line(char *line, char *buf)
{
	char	*new;
	size_t	i;

	i = 0;
	while (buf[i] && buf[i] != '\n' && i < BUFFER_SIZE)
		i++;
	new = malloc(sizeof(char) * (ft_strlen_t(line) + (buf[i] == '\n') + i + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (line && line[i])
	{
		new[i] = line[i];
		i++;
	}
	while (*buf && *buf != '\n')
		new[i++] = *buf++;
	if (*buf == '\n')
		new[i++] = '\n';
	new[i] = 0;
	if (line)
		free(line);
	return (new);
}

void	shift_buf(char *buf)
{
	size_t	i;
	size_t	dest;
	size_t	src;

	dest = 0;
	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	src = i + (buf[i] == '\n');
	while (buf[i])
		i++;
	while (src <= i)
		buf[dest++] = buf[src++];
	buf[dest] = 0;
}

size_t	ft_strlen_t(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == uc)
			return ((char *)s);
		s++;
	}
	if (*s == uc)
		return ((char *)s);
	return (NULL);
}

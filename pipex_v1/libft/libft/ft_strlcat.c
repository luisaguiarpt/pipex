/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:13:55 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/14 19:59:32 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;

	i = 0;
	s_len = ft_strlen(src);
	if (!size)
		return (s_len);
	d_len = ft_strlen(dst);
	if (size <= d_len)
		return (s_len + size);
	while (d_len + i < size - 1 && src[i])
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (d_len + s_len);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*dest = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
	printf("%lu\n", ft_strlcat(dest, "123", 0));
}
*/

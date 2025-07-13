/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:49:55 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/10 15:08:47 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d_str;
	unsigned char	*s_str;

	d_str = (unsigned char *)dest;
	s_str = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (dest <= src)
	{
		while (n--)
			*d_str++ = *s_str++;
	}
	else if (dest > src)
	{
		d_str += n - 1;
		s_str += n - 1;
		while (n--)
			*d_str-- = *s_str--;
	}
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*src = "lorem ipssum dolor sit a";
	char	*dest = src + 8;

	void	*ptr = ft_memmove(dest, src, 8);
	printf("%s\n", (char *)ptr);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:45:52 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/10 15:20:21 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d_str;
	unsigned char	*s_str;

	d_str = (unsigned char *)dest;
	s_str = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	while (n--)
		d_str[n] = s_str[n];
	return (dest);
}

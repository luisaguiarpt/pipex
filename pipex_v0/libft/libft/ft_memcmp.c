/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:32:07 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/10 18:24:39 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*t1;
	unsigned const char	*t2;

	t1 = (unsigned const char *)s1;
	t2 = (unsigned const char *)s2;
	if (n == 0)
		return (0);
	while (n--)
		if (*t1++ != *t2++)
			return (*(--t1) - *(--t2));
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*s1 = "abcdefghij";
	char	*s2 = "abcdefgxyz";
	int		res = ft_memcmp(s1, s2, 7);

	printf("%i\n", res);
}
*/

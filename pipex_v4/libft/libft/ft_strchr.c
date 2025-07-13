/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:31:24 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/10 20:44:37 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
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
/*
#include <stdio.h>

int	main(void)
{
	const char *s = "teste";
	int c = '\0';
	char *res = strchr(s, c);

	printf("%s\n\t%p\n", res, &res);
}
*/

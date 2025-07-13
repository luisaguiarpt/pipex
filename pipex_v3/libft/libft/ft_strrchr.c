/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:36:26 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/10 20:46:06 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*tmp;
	int				flag;
	unsigned char	uc;

	uc = (unsigned char)c;
	flag = 0;
	while (*s)
	{
		if (*s == uc)
		{
			tmp = (char *)s;
			flag = 1;
		}
		s++;
	}
	if (*s == uc)
	{
		tmp = (char *)s;
		flag = 1;
	}
	if (!flag)
		return (NULL);
	return (tmp);
}
/*
#include <stdio.h>

int	main(void)
{
	const char *s = "hello world";
	int c = 's';
	char *res = ft_strrchr(s, c);
	printf("%s\n", res);
}
*/

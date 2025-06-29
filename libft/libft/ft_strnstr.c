/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:34:11 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/14 20:01:32 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_match(const char *hay, const char *nee, size_t rmd);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (!(*little))
		return ((char *)big);
	if (!len)
		return (NULL);
	if (ft_strlen(little) > ft_strlen(big))
		return (NULL);
	while (*big && i < len)
	{
		if (is_match(big++, little, len - i))
			return ((char *)(--big));
		i++;
	}
	return (NULL);
}

static int	is_match(const char *hay, const char *nee, size_t rmd)
{
	size_t	len;

	len = ft_strlen(nee);
	while (*hay && len)
	{
		if ((*hay++ != *nee++) || !rmd)
			return (0);
		len--;
		rmd--;
	}
	return (1);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("%s\n", ft_strnstr("\0\0\0\0\0\0\0\0\0\0\0\0\0", "123", 0));
	printf("%s\n", strnstr("\0\0\0\0\0\0\0\0\0\0\0\0", "123", 0));
}
*/

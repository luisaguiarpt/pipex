/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:03:49 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/15 13:40:39 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(const char c, const char *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (is_set(s1[start], set))
		start++;
	if (start >= end)
		return (ft_strdup(""));
	while (is_set(s1[end], set))
		end--;
	trimmed = ft_substr(s1, start, end - start + 1);
	return (trimmed);
}

static int	is_set(const char c, const char *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

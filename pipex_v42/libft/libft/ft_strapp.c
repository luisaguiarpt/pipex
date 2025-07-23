/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strapp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 19:13:31 by ldias-da          #+#    #+#             */
/*   Updated: 2025/07/23 19:13:32 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_old(char **old, int old_size);

char	**ft_strappend(char **strs, char *to_append)
{
	int		n_strs;
	int		i;
	char	**new;

	if (!strs)
		return (NULL);
	n_strs = 0;
	while (strs[n_strs])
		n_strs++;
	new = ft_calloc(n_strs + 2, sizeof(char *));
	if (!new)
		return (NULL);
	i = 0;
	while (i < n_strs)
	{
		new[i] = ft_strdup(strs[i]);
		i++;
	}
	new[i++] = ft_strdup(to_append);
	new[i] = NULL;
	free_old(strs);
	free(to_append);
	return (new);
}

static void	free_old(char **old, int old_size)
{
	int	i;

	i = 0;
	while (i < old_size)
	{
		free(old[i]);
		i++;
	}
	free(old);
}

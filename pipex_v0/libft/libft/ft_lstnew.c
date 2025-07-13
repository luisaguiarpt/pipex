/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:04:15 by ldias-da          #+#    #+#             */
/*   Updated: 2025/05/29 12:54:12 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_slist	*ft_lstnew(void *content)
{
	t_slist	*new;

	new = (t_slist *)malloc(sizeof(t_slist));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->content = content;
	return (new);
}

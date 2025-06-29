/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:56:32 by ldias-da          #+#    #+#             */
/*   Updated: 2025/05/29 12:53:47 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_slist	*ft_lstmap(t_slist *lst, void *(*f)(void *), void (*del)(void *))
{
	t_slist	*map;
	t_slist	*node;
	void	*tmp;

	map = NULL;
	while (lst && f && del)
	{
		tmp = f(lst->content);
		if (!tmp)
		{
			ft_lstclear(&map, del);
			return (NULL);
		}
		node = ft_lstnew(tmp);
		if (!node)
		{
			del(tmp);
			ft_lstclear(&map, del);
			return (NULL);
		}
		ft_lstadd_back(&map, node);
		lst = lst->next;
	}
	return (map);
}

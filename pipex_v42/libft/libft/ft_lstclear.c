/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:27:54 by ldias-da          #+#    #+#             */
/*   Updated: 2025/05/29 12:52:16 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_slist **lst, void (*del)(void *))
{
	t_slist	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		if ((*lst)->content)
			ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	free(*lst);
	*lst = NULL;
}
/*
#include <stdio.h>

void	print_slist(t_slist *lst)
{
	while (lst)
	{
		printf("%s -> ", (char *)lst->content);
		lst = lst->next;
	}
	printf("\n");
}

void	delete_ls(void *addr)
{
	free(addr);
}

int	main(void)
{
	t_slist	*lst;
	t_slist	**ptr;
	t_slist	**ptr2;

	ptr = &lst;
	ptr2 = &lst;
	lst = ft_lstnew((void *)ft_strdup("1"));
	lst->next = ft_lstnew((void *)ft_strdup("2"));
	lst->next->next = ft_lstnew((void *)ft_strdup("3"));

	printf("Before: \n");
	print_slist(*ptr);
	ft_lstclear(&lst, delete_ls);
	printf("After: \n");
	print_slist(*ptr2);
}
*/

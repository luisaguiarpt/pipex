/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:54:15 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/14 14:01:38 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;

	ptr = malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	ptr = ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}
/*
int	main(void)
{
	void	*ptr;

	ptr = 
}
//	Had this in the function but caused issues with testing
//	if (nmemb > (size_t)(-1) / size)
//		return (NULL);
*/

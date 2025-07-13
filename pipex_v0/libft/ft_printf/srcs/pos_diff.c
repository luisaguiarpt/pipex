/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_diff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:31:36 by ldias-da          #+#    #+#             */
/*   Updated: 2025/05/22 13:01:49 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	pos_diff_ui(size_t a, size_t b)
{
	long int	la;
	long int	lb;
	long int	diff;

	la = (long int)a;
	lb = (long int)b;
	diff = la - lb;
	if (diff >= 0)
		return ((size_t)diff);
	else
		return (0);
}

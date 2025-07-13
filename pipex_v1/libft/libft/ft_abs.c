/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:02:41 by ldias-da          #+#    #+#             */
/*   Updated: 2025/05/28 16:28:03 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_abs(int n)
{
	if (n == INT_MIN)
		return (0);
	if (n < 0)
		return (-n);
	if (n >= 0)
		return (n);
	return (1);
}

double	ft_abs_dbl(double n)
{
	if (n < 0)
		return (-n);
	if (n >= 0)
		return (n);
	return (0);
}

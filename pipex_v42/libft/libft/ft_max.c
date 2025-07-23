/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:51:10 by ldias-da          #+#    #+#             */
/*   Updated: 2025/05/28 17:52:21 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

double	ft_max_dbl(double a, double b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

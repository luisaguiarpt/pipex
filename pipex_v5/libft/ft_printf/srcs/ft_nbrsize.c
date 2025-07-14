/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:31:36 by ldias-da          #+#    #+#             */
/*   Updated: 2025/05/22 12:49:12 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../../libft/libft.h"

size_t	abs_nbr_dig(int n)
{
	size_t	digits;

	digits = 0;
	if (n == INT_MIN)
		return (10);
	if (n == 0)
		digits += 1;
	while (n != 0)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}

size_t	u_nbr_dig(unsigned int n)
{
	size_t	digits;

	digits = 0;
	if (n == 0)
		digits += 1;
	while (n != 0)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}

size_t	hex_nbr_dig(unsigned int n)
{
	size_t	digits;

	digits = 0;
	if (n == 0)
		digits += 1;
	while (n != 0)
	{
		digits++;
		n /= 16;
	}
	return (digits);
}

size_t	nbr_dig(int n)
{
	size_t	digits;

	digits = 0;
	if (n == INT_MIN)
		return (11);
	if (n == 0)
		digits += 1;
	if (n < 0)
	{
		digits += 1;
		n *= -1;
	}
	while (n > 0)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}

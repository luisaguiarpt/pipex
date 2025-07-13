/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:04:30 by ldias-da          #+#    #+#             */
/*   Updated: 2025/05/22 12:59:54 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	putchar_format(char c, t_format *format)
{
	size_t	i;

	i = 0;
	if (format->minus)
		write(1, &c, 1);
	while (i < format->min - (format->min > 0) * 1)
	{
		write(1, " ", 1);
		i++;
	}
	if (!format->minus)
		write(1, &c, 1);
	return (1 + i);
}

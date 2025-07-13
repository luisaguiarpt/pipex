/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 21:07:19 by ldias-da          #+#    #+#             */
/*   Updated: 2025/05/22 13:01:21 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../includes/ft_printf.h"

size_t	ft_min_size_t(size_t a, size_t b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

int	is_flag(char c)
{
	if (c == '0' || c == '#' || c == '+' || c == '-' || c == ' ')
		return (1);
	return (0);
}

int	is_max(const char *str, t_format *format)
{
	int	i;

	i = 0;
	if (str[i] == '.')
	{
		format->prec = 1;
		return (1);
	}
	else
		return (0);
}

int	is_type(char c)
{
	if (c == 'i' || c == 'd' || c == 'u' || c == 'p')
		return (1);
	if (c == 'x' || c == 'X' || c == 'c' || c == 's')
		return (1);
	if (c == '%')
		return (1);
	return (0);
}

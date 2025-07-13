/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 21:30:02 by ldias-da          #+#    #+#             */
/*   Updated: 2025/05/22 13:01:12 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../includes/ft_printf.h"

int	parse_str(const char *str, t_format *format)
{
	int	i;

	i = 0;
	while (is_flag(str[i]) && str[i])
		get_flags(str[i++], format);
	if (ft_isdigit(str[i]) && str[i])
		i += get_nbr(&str[i], format, 'n');
	if (is_max(&str[i], format) && str[i])
	{
		++i;
		i += get_nbr(&str[i], format, 'x');
	}
	if (is_type(str[i]) && str[i])
		i += get_type(str[i], format);
	check_error(format);
	return (i);
}

void	get_flags(char c, t_format *format)
{
	if (c == '0')
		format->zero += 1;
	if (c == '#')
		format->hash += 1;
	if (c == '+')
		format->plus += 1;
	if (c == '-')
		format->minus += 1;
	if (c == ' ')
		format->blank += 1;
}

int	get_type(char c, t_format *format)
{
	if (c == 'i')
		format->type = 'i';
	if (c == 'd')
		format->type = 'd';
	if (c == 'u')
		format->type = 'u';
	if (c == 'x')
		format->type = 'x';
	if (c == 'X')
		format->type = 'X';
	if (c == 'p')
		format->type = 'p';
	if (c == 'c')
		format->type = 'c';
	if (c == 's')
		format->type = 's';
	if (c == '%')
		format->type = '%';
	if (c == 'i' || c == 'd' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	else if (c == 'p' || c == 'c' || c == 's' || c == '%')
		return (1);
	return (0);
}

int	get_nbr(const char *str, t_format *format, char min_max)
{
	int	nbr;
	int	i;

	nbr = 0;
	i = 0;
	while (ft_isdigit(str[i]))
	{
		nbr = (nbr * 10) + str[i] - '0';
		i++;
	}
	if (min_max == 'n')
		format->min = nbr;
	if (min_max == 'x')
		format->max = nbr;
	return (i);
}

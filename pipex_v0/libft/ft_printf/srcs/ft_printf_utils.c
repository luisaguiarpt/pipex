/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 21:30:02 by ldias-da          #+#    #+#             */
/*   Updated: 2025/05/22 13:01:37 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../includes/ft_printf.h"

void	check_error(t_format *format)
{
	if (format->zero > 1 || format->hash > 1 || format->plus > 1)
		format->error = 1;
	if (format->minus > 1 || format->blank > 1)
		format->error = 1;
}

int	init_flags(t_format **f_ptr)
{
	t_format	*format;

	format = malloc(sizeof(t_format));
	if (!format)
		return (0);
	if (*f_ptr != NULL)
		free(*f_ptr);
	*f_ptr = format;
	format->zero = 0;
	format->hash = 0;
	format->plus = 0;
	format->minus = 0;
	format->blank = 0;
	format->min = 0;
	format->prec = 0;
	format->max = 0;
	format->type = '\0';
	format->error = 0;
	return (1);
}

size_t	get_function(t_format *format, char c, va_list args)
{
	if (c == 'c')
		return (putchar_format(va_arg(args, int), format));
	else if (c == 's')
		return (putstr_format(va_arg(args, char *), format));
	else if (c == 'i' || c == 'd')
		return (putnbr_format(va_arg(args, int), format));
	else if (c == 'u')
		return (putnbr_u_format(va_arg(args, unsigned int), format));
	else if (c == 'x' || c == 'X')
		return (puthex_format(va_arg(args, unsigned int), format));
	else if (c == 'p')
		return (putptr_format(va_arg(args, unsigned long), format));
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}

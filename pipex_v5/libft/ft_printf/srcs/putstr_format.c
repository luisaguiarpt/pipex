/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:09:09 by ldias-da          #+#    #+#             */
/*   Updated: 2025/05/22 13:00:13 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../../libft/libft.h"

static size_t	putnstr(char *str, t_format *format);
static size_t	put_spaces(char *str, t_format *format);
static size_t	putstr_null(t_format *format);

size_t	putstr_format(char *s, t_format *format)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		i += putstr_null(format);
		return (i);
	}
	if (!format->minus)
		i += put_spaces(s, format);
	i += putnstr(s, format);
	if (format->minus)
		i += put_spaces(s, format);
	return (i);
}

static size_t	putstr_null(t_format *format)
{
	size_t	i;
	size_t	spaces;
	size_t	write_null;

	i = 0;
	write_null = 0;
	if (format->prec && format->max < 6)
		spaces = format->min;
	else
	{
		write_null = 1;
		spaces = pos_diff_ui(format->min, 6);
	}
	if (!format->minus)
		while (i++ < spaces)
			write(1, " ", 1);
	if (write_null)
		write(1, "(null)", 6);
	if (format->minus)
		while (i++ < spaces)
			write(1, " ", 1);
	return (spaces + write_null * 6);
}

static size_t	putnstr(char *str, t_format *format)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = format->max;
	if (!format->max && format->prec)
		n = 0;
	else if (!format->max && !format->prec)
		n = ft_strlen(str);
	while (i < n && str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

static size_t	put_spaces(char *str, t_format *format)
{
	size_t	spaces;
	size_t	to_write;
	size_t	i;

	spaces = 0;
	to_write = 0;
	i = 0;
	if (!format->prec)
		to_write = ft_strlen(str);
	else if (format->prec && format->max < ft_strlen(str))
		to_write = format->max;
	else if (format->prec && format->max >= ft_strlen(str))
		to_write = ft_strlen(str);
	if (format->min && format->min > to_write)
		spaces = format->min - to_write;
	else
		spaces = 0;
	while (i < spaces)
	{
		write(1, " ", 1);
		i++;
	}
	return (spaces);
}
/*
int	main(void)
{
	t_format	*format;
	
	format = malloc(sizeof(t_format));
	format->minus = 1;
	format->min = 4;
	format->max = 4;

	char	*str = "Hello";
	ft_putstr(str, format);
}
*/

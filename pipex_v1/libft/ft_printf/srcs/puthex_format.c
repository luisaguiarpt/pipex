/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:08:49 by ldias-da          #+#    #+#             */
/*   Updated: 2025/05/22 13:00:26 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	puthex(unsigned int n, t_format *format);
static size_t	put_zeros(unsigned int n, t_format *format, int put);
static size_t	put_spaces(unsigned int n, t_format *format);
static size_t	put_hash(unsigned int n, t_format *format, int put);

size_t	puthex_format(unsigned int n, t_format *format)
{
	size_t	count;

	count = 0;
	if (!format->minus && (!format->zero || format->prec))
		count += put_spaces(n, format);
	if (format->hash)
		count += put_hash(n, format, 1);
	count += put_zeros(n, format, 1);
	count += puthex(n, format);
	if (format->minus)
		count += put_spaces(n, format);
	return (count);
}

static size_t	puthex(unsigned int n, t_format *format)
{
	unsigned char	c;
	const char		*hex;
	size_t			count;

	count = 0;
	if (format->prec && !format->max && n == 0)
		return (0);
	if (format->type == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n > 15)
		count += puthex(n / 16, format);
	c = hex[n % 16];
	write(1, &c, 1);
	count++;
	return (count);
}

static size_t	put_hash(unsigned int n, t_format *format, int put)
{
	if (format->hash && n == 0)
		return (0);
	if (format->hash && format->type == 'x')
	{
		if (put)
			write(1, "0x", 2);
		return (2);
	}
	if (format->hash && format->type == 'X')
	{
		if (put)
			write(1, "0X", 2);
		return (2);
	}
	return (0);
}

static size_t	put_spaces(unsigned int n, t_format *format)
{
	size_t	spaces;
	size_t	i;
	size_t	len;

	if (format->prec && format->max > format->min)
		return (0);
	spaces = format->min;
	len = put_hash(n, format, 0);
	if (format->prec && format->max == 0 && n == 0)
		len += 0;
	else
		len += hex_nbr_dig(n);
	if (format->max > hex_nbr_dig(n))
		len += format->max - hex_nbr_dig(n);
	spaces = pos_diff_ui(spaces, len);
	i = 0;
	while (i < spaces)
	{
		write(1, " ", 1);
		i++;
	}
	return (spaces);
}

static size_t	put_zeros(unsigned int n, t_format *format, int put)
{
	size_t	zeros;
	size_t	i;
	size_t	total_width;

	i = 0;
	total_width = 0;
	if (format->max)
		zeros = pos_diff_ui(format->max, hex_nbr_dig(n));
	else if (format->zero && !format->prec)
	{
		total_width = format->min;
		total_width -= put_hash(n, format, 0);
		zeros = pos_diff_ui(total_width, hex_nbr_dig(n));
	}
	else
		zeros = 0;
	while (i < zeros && put)
	{
		write(1, "0", 1);
		i++;
	}
	return (zeros);
}
/*
#include <stdio.h>

int	main(void)
{
	unsigned int	n = 0;
	n = ft_puthex(0);
	printf("|%u\n", n);
	printf("|%x\n", 0);
	n = ft_puthex(5);
	printf("|%u\n", n);
	printf("|%x\n", 5);
	n = ft_puthex(42);
	printf("|%u\n", n);
	printf("|%x\n", 42);
	n = ft_puthex(101230);
	printf("|%u\n", n);
	printf("|%x\n", 101230);
	n = ft_puthex(-123094);
	printf("|%u\n", n);
	printf("|%x\n", -123094);
	n = ft_puthex(-2147483647);
	printf("|%u\n", n);
	printf("|%x\n", -2147483647);
	n = ft_puthex(2147483647);
	printf("|%u\n", n);
	printf("|%x\n", 2147483647);
}
*/

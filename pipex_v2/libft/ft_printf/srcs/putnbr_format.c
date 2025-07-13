/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:08:49 by ldias-da          #+#    #+#             */
/*   Updated: 2025/05/22 12:58:32 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../../libft/libft.h"

static size_t	put_spaces(int n, t_format *format);
static size_t	put_zeros(int n, t_format *format, int put);
static size_t	put_sign(int n, t_format *format, int put);
static size_t	put_nbr(int n, t_format *format);

size_t	putnbr_format(int n, t_format *format)
{
	size_t	count;

	count = 0;
	if (!format->minus && (!format->zero || format->prec))
		count += put_spaces(n, format);
	count += put_sign(n, format, 1);
	count += put_zeros(n, format, 1);
	count += put_nbr(n * ((n < 0) * -1 + 1 * (n > 0)), format);
	if (format->minus)
		count += put_spaces(n, format);
	return (count);
}

static size_t	put_sign(int n, t_format *format, int put)
{
	if (format->plus && n >= 0)
	{
		if (put)
			write(1, "+", 1);
		return (1);
	}
	else if (format->blank && n >= 0)
	{
		if (put)
			write(1, " ", 1);
		return (1);
	}
	else if (n < 0)
	{
		if (put)
			write(1, "-", 1);
		return (1);
	}
	return (0);
}

static size_t	put_zeros(int n, t_format *format, int put)
{
	size_t	zeros;
	size_t	i;
	size_t	total_width;

	i = 0;
	total_width = 0;
	if (format->max)
		zeros = pos_diff_ui(format->max, abs_nbr_dig(n));
	else if (format->zero && !format->prec)
	{
		total_width = format->min;
		total_width -= put_sign(n, format, 0);
		zeros = pos_diff_ui(total_width, abs_nbr_dig(n));
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

static size_t	put_spaces(int n, t_format *format)
{
	size_t	spaces;
	size_t	i;
	size_t	len;

	if (format->prec && format->max > format->min)
		return (0);
	spaces = format->min;
	len = put_sign(n, format, 0);
	if (format->prec && format->max == 0 && n == 0)
		len += 0;
	else
		len += abs_nbr_dig(n);
	if (format->max > abs_nbr_dig(n))
		len += format->max - abs_nbr_dig(n);
	spaces = pos_diff_ui(spaces, len);
	i = 0;
	while (i < spaces)
	{
		write(1, " ", 1);
		i++;
	}
	return (spaces);
}

static size_t	put_nbr(int n, t_format *format)
{
	char	c;
	size_t	count;

	count = 0;
	if (format->prec && format->max == 0 && n == 0)
		return (0);
	if (n == INT_MIN)
	{
		write(1, "2147483648", 10);
		return (10);
	}
	if (n > 9)
		count += put_nbr(n / 10, format);
	c = (n % 10) + '0';
	write(1, &c, 1);
	count++;
	return (count);
}
/*
#include <stdio.h>

int	main(void)
{
	int	n = 0;
	int	m = 0;

	t_format	*format;

	format = malloc(sizeof(t_format));
	format->min = 9;
	format->max = 6;
	format->minus = 0;
	format->zero = 1;
	format->plus = 1;

	n = putnbr_format(1243, format);
	printf("|%i\n", n);
	m = printf("%+09i", 1243);
	printf("|%i\n", m);
	printf("------------------\n");
	n = putnbr_format(1234, format);
	printf("|%i\n", n);
	m = printf("%+09i", 1234);
	printf("|%i\n", m);
	printf("------------------\n");
	n = putnbr_format(9876, format);
	printf("|%i\n", n);
	m = printf("%+09i", 9876);
	printf("|%i\n", m);
	printf("------------------\n");
	n = putnbr_format(-1243, format);
	printf("|%i\n", n);
	m = printf("%+09i", -1243);
	printf("|%i\n", m);
	printf("------------------\n");
	n = putnbr_format(-21648, format);
	printf("|%i\n", n);
	m = printf("%+09i", -21648);
	printf("|%i\n", m);
	printf("------------------\n");
	n = putnbr_format(2147, format);
	printf("|%i\n", n);
	m = printf("%+09i", 2147);
	printf("|%i\n", m);
}
*/

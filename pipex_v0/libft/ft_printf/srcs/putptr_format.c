/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putptr_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:08:49 by ldias-da          #+#    #+#             */
/*   Updated: 2025/05/22 13:00:49 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/ft_printf.h"
#include "../../libft/libft.h"

static size_t	ptrsize(unsigned long int n);
static size_t	putptr(unsigned long int n);
static size_t	prt_nil(void);

size_t	putptr_format(unsigned long int n, t_format *format)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!format->minus && format->min > ptrsize(n))
	{
		while (i < format->min - ptrsize(n))
		{
			write(1, " ", 1);
			i++;
			count++;
		}
	}
	count += putptr(n);
	if (format->minus && format->min > ptrsize(n))
	{
		while (i < format->min - ptrsize(n))
		{
			write(1, " ", 1);
			i++;
			count++;
		}
	}
	return (count);
}

static size_t	ptrsize(unsigned long int n)
{
	unsigned int	count;

	count = 0;
	if (n == 0)
		return (5);
	if (n > 15)
		count += ptrsize(n / 16);
	if (count == 0)
		count += 2;
	count++;
	return (count);
}

static size_t	prt_nil(void)
{
	write(1, "(nil)", 5);
	return (5);
}

static size_t	putptr(unsigned long int n)
{
	unsigned char	c;
	const char		*hex;
	unsigned int	count;

	count = 0;
	hex = "0123456789abcdef";
	if (n == 0)
		return (prt_nil());
	if (n > 15)
		count += putptr(n / 16);
	c = hex[n % 16];
	if (count == 0)
	{
		write(1, "0x", 2);
		count += 2;
	}
	write(1, &c, 1);
	count++;
	return (count);
}
/*
#include <stdio.h>

int	main(void)
{
	unsigned int	n = 0;
	unsigned int	m = 0;

	int	a = 1;
	int	*ptr1 = &a;
	n = ft_putptr((unsigned long int)ptr1);
	printf("|%u\n", n);
	m = printf("%p", ptr1);
	printf("|%u\n-------------\n", m);

	char	*ptr2 = "ola";
	n = ft_putptr((unsigned long int)ptr2);
	printf("|%u\n", n);
	m = printf("%p", ptr2);
	printf("|%u\n-------------\n", m);
	
	n = ft_putptr(0);
	printf("|%u\n", n);
	m = printf("%p", (void *)0);
	printf("|%u\n-------------\n", m);
	m = 0;

	n = ft_putptr(5);
	printf("|%u\n", n);
	m = printf("%p", (void *)5);
	printf("|%u\n-------------\n", m);
	m = 0;

	n = ft_putptr(42);
	printf("|%u\n", n);
	m = printf("%p", (void *)42);
	printf("|%u\n-------------\n", m);
	m = 0;

	n = ft_putptr(101230);
	printf("|%u\n", n);
	m = printf("%p", (void *)101230);
	printf("|%u\n-------------\n", m);
	m = 0;

	n = ft_putptr(-123094);
	printf("|%u\n", n);
	m = printf("%p", (void *)-123094);
	printf("|%u\n-------------\n", m);
	m = 0;

	n = ft_putptr(-2147483647);
	printf("|%u\n", n);
	m = printf("%p", (void *)-2147483647);
	printf("|%u\n-------------\n", m);
	m = 0;

	n = ft_putptr(2147483647);
	printf("|%u\n", n);
	m = printf("%p", (void *)2147483647);
	printf("|%u\n-------------\n", m);
	m = 0;
}
*/

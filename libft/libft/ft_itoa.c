/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 11:17:55 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/15 10:42:40 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_size(int n);
static char	*str_rev(char *str);

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		neg;

	neg = 0;
	i = -1;
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	str = (char *)ft_calloc((num_size(n) + 1), sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
		neg = 1;
	if (n < 0)
		n *= -1;
	while (num_size(n) && n)
	{
		str[++i] = (n % 10) + '0';
		n /= 10;
	}
	if (neg)
		str[++i] = '-';
	return (str_rev(str));
}

static char	*str_rev(char *str)
{
	int		n;
	int		i;
	char	c;

	n = ft_strlen(str);
	i = 0;
	while (i < n / 2)
	{
		c = str[i];
		str[i] = str[n - i - 1];
		str[n - i - 1] = c;
		i++;
	}
	return (str);
}

static int	num_size(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}
/*
#include <stdio.h>

int	main(void)
{
	int	i = -9;
	char	*str = ft_itoa(i);

	printf("%s\n", str);
}
*/

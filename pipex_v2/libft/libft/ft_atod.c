/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:23:31 by ldias-da          #+#    #+#             */
/*   Updated: 2025/05/29 20:33:07 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_space(char c);
static double	get_double(char *str);

double	ft_atod(char *str)
{
	double	sign;
	int		i;

	sign = 1;
	i = 0;
	while (str[i] && is_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	return (sign * get_double(&str[i]));
}

static double	get_double(char *str)
{
	int		i;
	double	whole;
	double	decimal;
	double	prec;

	i = 0;
	whole = 0.0;
	decimal = 0.0;
	prec = 10.0;
	while (str[i] && ft_isdigit(str[i]))
		whole = 10 * whole + str[i++] - '0';
	if (str[i] != '.' || !str[i])
		return (whole);
	i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		decimal = decimal + ((str[i] - '0') / prec);
		prec *= 10.0;
		i++;
	}
	return (whole + decimal);
}

static int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}
//
//#include <stdio.h>
//
//int	main(void)
//{
//	printf("%10.10f\n", ft_atod("0"));
//	printf("%10.10f\n", ft_atod("0.000123"));
//	printf("%10.10f\n", ft_atod("-123.000000001"));
//	printf("%10.10f\n", ft_atod("+0"));
//	printf("%10.10f\n", ft_atod("-123"));
//	printf("%10.10f\n", ft_atod("-0.12312424"));
//	printf("%10.10f\n", ft_atod("2.123"));
//}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdouble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:11:39 by ldias-da          #+#    #+#             */
/*   Updated: 2025/05/30 11:25:56 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdouble(char *str)
{
	int	i;
	int	dot;
	int	sign;
	int	numbers;

	i = 0;
	dot = 0;
	sign = 0;
	numbers = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i])
	{
		if (str[i] == '.')
			dot += 1;
		else if (str[i] == '+' || str[i] == '-')
			sign += 1;
		else if (str[i] >= '0' && str[i] <= '9')
			numbers += 1;
		i++;
	}
	if (dot < 2 && sign < 2 && numbers > 0)
		return (1);
	else
		return (0);
}
//
//#include <stdio.h>
//
//int	main(void)
//{
//	printf("%s -> %i\n", "0", ft_isdouble("0"));
//	printf("%s -> %i\n", "-0.123", ft_isdouble("-0.123"));
//	printf("%s -> %i\n", "++", ft_isdouble("++"));
//	printf("%s -> %i\n", "2.3.1", ft_isdouble("2.3.1"));
//	printf("%s -> %i\n", "-.123", ft_isdouble("-.123"));
//}

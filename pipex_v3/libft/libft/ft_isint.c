/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:29:57 by ldias-da          #+#    #+#             */
/*   Updated: 2025/06/02 17:32:30 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isint(char *str)
{
	int	i;
	int	sign;
	int	number;

	i = 0;
	sign = 0;
	number = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = 1;
		i++;
	}
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			number = 1;
			i++;
		}
		else
			return (0);
	}
	return (sign * number + number);
}

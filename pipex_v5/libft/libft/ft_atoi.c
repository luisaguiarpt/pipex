/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:45:18 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/15 11:37:24 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(char c);

int	ft_atoi(const char *str)
{
	int	nbr;
	int	minus;

	minus = 1;
	nbr = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			minus = -1;
	while (*str >= '0' && *str <= '9')
		nbr = (nbr * 10) + (*str++ - '0');
	return (minus * nbr);
}

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

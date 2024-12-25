/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 02:26:55 by obelhami          #+#    #+#             */
/*   Updated: 2024/12/25 03:49:27 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_atof_dbl(char *str, double *factorial, int i)
{
	int	test;

	test = 10;
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			*factorial = *factorial + ((double)(str[i] - '0') / test);
			i++;
			test *= 10;
		}
	}
}

float	ft_atof(char *str)
{
	int		i;
	double	sign;
	double	factorial;

	i = 0;
	sign = 1.0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	factorial = 0.0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		factorial = (10 * factorial) + str[i] - '0';
		i++;
	}
	ft_atof_dbl(str, &factorial, i);
	if (factorial == 0.0)
		sign = 1.0;
	return (factorial * sign);
}

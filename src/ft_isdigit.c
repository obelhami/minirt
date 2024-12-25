/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 02:27:07 by obelhami          #+#    #+#             */
/*   Updated: 2024/12/25 04:23:48 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_ft_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && (str[0] == '-' || str[0] == '+'))
			i++;
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

int	ft_isfloat(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (i == 0 && (str[0] == '-' || str[0] == '+'))
			i++;
		else if (str[i] == '.' && i)
		{
			i++;
			flag = 1;
		}
		if (str[i] >= '0' && str[i] <= '9' && flag < 2)
			i++;
		else
			return (1);
	}
	return (0);
}

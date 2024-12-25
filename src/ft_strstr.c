/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 02:27:13 by obelhami          #+#    #+#             */
/*   Updated: 2024/12/25 02:27:17 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_strstr(char *str, char *to_find)
{
	int	j;
	int	i;

	if (!to_find || !str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (to_find[j] == str[i + j])
		{
			if (!to_find[j] && !str[i + j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

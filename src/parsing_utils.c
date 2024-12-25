/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 02:27:29 by obelhami          #+#    #+#             */
/*   Updated: 2024/12/25 02:27:30 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fill_coordinate(t_vec3 *object, char **coordinate)
{
	object->x = ft_atof(coordinate[0]);
	object->y = ft_atof(coordinate[1]);
	object->z = ft_atof(coordinate[2]);
}

void	fill_rgb(t_rgb *object, char **rgb)
{
	object->r = ft_atoi(rgb[0]);
	object->g = ft_atoi(rgb[1]);
	object->b = ft_atoi(rgb[2]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ambient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 06:39:08 by obelhami          #+#    #+#             */
/*   Updated: 2024/12/29 04:57:26 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ambient	*create_ambient(char **split)
{
	t_ambient		*ambient;
	char			**rgb;
	double			light_ratio;

	ambient = malloc(sizeof(t_ambient));
	if (ft_dblptrlen(split) != 3)
		utils("argumment of ambient");
	light_ratio = ft_atof(split[1]);
	if (light_ratio < 0.0 || light_ratio > 1.0)
		utils("light ratio");
	ambient->lighting_ratio = light_ratio;
	rgb = ft_split(split[2], ',');
	ft_check_rgb(rgb, "ambient");
	fill_rgb(&ambient->color, rgb);
	return (ambient);
}

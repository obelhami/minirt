/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 06:15:01 by obelhami          #+#    #+#             */
/*   Updated: 2024/12/29 20:43:33 by ajawad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light	*create_light(char **split)
{
	double	brightness;
	char	**coordinate;
	char	**rgb;
	t_light	*light;

	light = alloc(sizeof(t_light));
	if (ft_dblptrlen(split) != 4)
		utils("light");
	coordinate = ft_split(split[1], ',');
	ft_check_isfloat(coordinate, "coordinates");
	fill_coordinate(&light->cord, coordinate);
	brightness = ft_atof(split[2]);
	if (ft_isfloat(split[2]) || (brightness < 0.0 || brightness > 1.0))
		utils("brightness");
	light->brightness = brightness;
	rgb = ft_split(split[3], ',');
	ft_check_rgb(rgb, "light");
	fill_rgb(&light->color, rgb);
	return (light);
}

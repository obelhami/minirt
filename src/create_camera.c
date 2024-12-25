/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 06:27:49 by obelhami          #+#    #+#             */
/*   Updated: 2024/12/25 06:27:50 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	check_orientation_vec(t_camera *camera, char **split)
{
	int		i;
	char	**orientation_vector;

	orientation_vector = ft_split(split[2], ',');
	i = 0;
	while (orientation_vector[i])
	{
		if (ft_isfloat(orientation_vector[i])
			|| (ft_atof(orientation_vector[i]) < -1.00
				|| ft_atof(orientation_vector[i]) > 1.00))
			utils("orientation_vector");
		i++;
	}
	if (i != 3)
		utils("orientation_vector");
	fill_coordinate(&camera->orientation_vec, orientation_vector);
}

t_camera	*create_camera(char **split)
{
	t_camera	*camera;
	int			fov;
	char		**coordinate;

	camera = malloc(sizeof(t_camera));
	if (ft_dblptrlen(split) != 4)
		utils("argumment of camera");
	coordinate = ft_split(split[1], ',');
	ft_check_isfloat(coordinate, "coordinates");
	fill_coordinate(&camera->cord, coordinate);
	check_orientation_vec(camera, split);
	fov = ft_atof(split[3]);
	if (ft_ft_isdigit(split[3]) || (fov < 0 || fov > 180))
		utils("field of view");
	camera->hfov = fov;
	return (camera);
}

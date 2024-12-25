/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 06:05:53 by obelhami          #+#    #+#             */
/*   Updated: 2024/12/25 06:05:56 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static	void	check_orientation_vector(t_plane *plane, char **split)
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
		{
			printf("Error: the coordinates is invalid1\n");
			exit(1);
		}
		i++;
	}
	if (i != 3)
		utils("orientation_vector");
	fill_coordinate(&plane->normal_vec, orientation_vector);
}

t_plane	*create_plane(char **split)
{
	char	**coordinate;
	char	**rgb;
	t_plane	*plane;

	plane = malloc(sizeof(t_plane));
	if (ft_dblptrlen(split) != 4)
		utils("argumment of plane");
	coordinate = ft_split(split[1], ',');
	ft_check_isfloat(coordinate, "coordinates");
	fill_coordinate(&plane->point_cord, coordinate);
	check_orientation_vector(plane, split);
	rgb = ft_split(split[3], ',');
	ft_check_rgb(rgb, "plane");
	fill_rgb(&plane->color, rgb);
	return (plane);
}

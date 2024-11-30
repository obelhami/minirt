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

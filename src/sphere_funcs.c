/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajawad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:51:48 by ajawad            #+#    #+#             */
/*   Updated: 2024/12/13 15:01:41 by ajawad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere	*create_sphere(char **split)
{
	char		**coordinate;
	int			i;
	double		diameter;
	char		**rgb;
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (ft_dblptrlen(split) != 4)
	{
		printf("Error: the argumment of sphere is invalid\n");
		exit(1);
	}
	coordinate = ft_split(split[1], ',');
	i = 0;
	while (coordinate[i])
	{
		if (ft_isfloat(coordinate[i]))
		{
			printf("Error: the coordinates is invalid10\n");
			exit(1);
		}
		i++;
	}
	if (i != 3)
	{
		printf("Error: the coordinates is invalid11\n");
		exit(1);
	}
	fill_coordinate(&sphere->center, coordinate);
	diameter = ft_atof(split[2]);
	if (ft_isfloat(split[2]) || diameter < 0.0)
	{
		printf("the range of diameter is invalid\n");
		exit(1);
	}
	sphere->diameter = diameter;
	sphere->radius = diameter / 2;
	rgb = ft_split(split[3], ',');
	i = 0;
	while (rgb[i])
	{
		if (ft_ft_isdigit(rgb[i]) == 1)
		{
			printf("Error: the color of sphere is invalid\n");
			exit(1);
		}
		if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
		{
			printf("Error: the color of sphere is invalid\n");
			exit(1);
		}
		i++;
	}
	if (i != 3)
	{
		printf("Error: the coordinates is invalid12\n");
		exit(1);
	}
	fill_rgb(&sphere->color, rgb);
	ft_free(split);
	return (sphere);
}

static void	set_record(t_hit_record *rec, t_sphere *sphere, t_ray *ray,
		double root)
{
	rec->t = root;
	rec->point = ray_at(ray, rec->t);
	rec->normal = division_op(subtraction_op(rec->point, &sphere->center),
			sphere->radius);
	set_normal_against_ray(ray, rec);
	rec->color = &sphere->color;
}

BOOL	hit_sphere(void *ptr, t_interval interval, t_hit_record *rec,
		t_ray *ray)
{
	t_sphere		*sphere;
	t_vec3			*oc;
	t_discriminant	eq;
	double			sqrt_delta;
	double			root;

	sphere = (t_sphere *)ptr;
	oc = subtraction_op(&sphere->center, ray->orig);
	eq.a = vector_length_squared(ray->dir);
	eq.b = -2.0 * dot_product(ray->dir, oc);
	eq.c = vector_length_squared(oc)
		- (sphere->radius * sphere->radius);
	eq.delta = (eq.b * eq.b) - (4 * eq.a * eq.c);
	if (eq.delta < 0)
		return (FALSE);
	sqrt_delta = sqrt(eq.delta);
	root = (-eq.b - sqrt_delta) / (2.0 * eq.a);
	if (root <= interval.min || root >= interval.max)
	{
		root = (-eq.b + sqrt_delta) / (2.0 * eq.a);
		if (root <= interval.min || root >= interval.max)
			return (FALSE);
	}
	return (set_record(rec, sphere, ray, root), TRUE);
}

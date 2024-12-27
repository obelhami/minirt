/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajawad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:46:35 by ajawad            #+#    #+#             */
/*   Updated: 2024/12/27 21:21:30 by ajawad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb	*ray_color(t_world_setup *world_setup, t_ray *ray)
{
	t_interval		interval;
	t_hit_record	rec;

	interval.min = 0.0;
	interval.max = INFINITY;
	if (hit_any_object(world_setup->world, interval, &rec, ray))
		return (scale_color(calculate_light(world_setup, &rec, ray),
					rec.color));
	return (scale_color(world_setup->ambient->lighting_ratio,
				&world_setup->ambient->color));
}

t_ray	*get_ray(int jdx, int idx, t_world_setup *world_setup)
{
	t_vec3		offset;
	T_POINT3	*pixel_sample;
	t_ray		*ray;

	fill_vec3(&offset, random_double() - 0.5, random_double() - 0.5, 0);
	pixel_sample = addition_op(world_setup->pixel00_loc, addition_op(
				scalar_op(jdx + offset.x, world_setup->delta_u),
				scalar_op(idx + offset.y, world_setup->delta_v)));
	ray = malloc(sizeof(t_ray));
	if (ray == NULL)
		return (NULL);
	ray->orig = &world_setup->camera->cord;
	ray->dir = subtraction_op(pixel_sample, ray->orig);
	return (ray);
}

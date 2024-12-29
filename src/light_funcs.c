/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajawad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:12:04 by ajawad            #+#    #+#             */
/*   Updated: 2024/12/29 05:57:29 by ajawad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	hit_light(t_object_container *world, t_ray *ray, t_light *light)
{
	t_interval		interval;
	t_hit_record	rec;

	interval.min = EPSILON;
	interval.max = vector_length(subtraction_op(&light->cord, ray->orig));
	while (world != NULL)
	{
		if (world->hit(world->object, interval, &rec, ray))
			return (FALSE);
		world = world->next;
	}
	return (TRUE);
}

double	calculate_light_effect(t_world_setup *world_setup, t_hit_record *rec)
{
	t_vec3			*light_dir;
	double			diffuse;
	t_ray			light_ray;

	light_dir = unit_vector(subtraction_op(&world_setup->light->cord,
				rec->point));
	diffuse = max(0.0, dot_product(light_dir, rec->normal))
		* world_setup->light->brightness;
	if (diffuse == 0)
		return (world_setup->ambient->lighting_ratio);
	light_ray.orig = rec->point;
	light_ray.dir = light_dir;
	if (hit_light(world_setup->world, &light_ray, world_setup->light) == FALSE)
		return (world_setup->ambient->lighting_ratio);
	return (diffuse + world_setup->ambient->lighting_ratio);
}

#include "minirt.h"

t_rgb	*ray_color(t_world_setup *world_setup, t_ray *ray)
{
	t_rgb			*color;
	t_interval		interval;
	t_hit_record	rec;
	
	interval.min = 0;
	interval.max = INFINITY;
	if (hit_any_object(world_setup->world, interval, &rec, ray))
	{
		color = scale_color(calculate_light(world_setup, &rec, ray), rec.color);
		return (color);
	}
	color = malloc(sizeof(t_rgb));
	if (color == NULL)
		return (NULL);
	color->r = 0;
	color->g = 0;
	color->b = 0;
	return (color);
}

t_ray	*get_ray(int jdx, int idx, t_world_setup *world_setup)
{
	t_vec3		*offset;
	T_POINT3	*pixel_sample;
	t_ray		*ray;
	
	offset = create_vec3(random_double() - 0.5, random_double() - 0.5, 0);
	pixel_sample = addition_op(world_setup->pixel00_loc, addition_op(
				scalar_op(jdx + offset->x, world_setup->delta_u),
				scalar_op(idx + offset->y, world_setup->delta_v)));
	ray = malloc(sizeof(t_ray));
	if (ray == NULL)
		return (NULL);
	ray->orig = &world_setup->camera->cord;
	ray->dir = subtraction_op(pixel_sample, ray->orig);
	return (ray);
}

#include "minirt.h"

BOOL	hit_light(t_object_container *world, t_ray *ray, t_light *light)
{
	t_interval		interval;
	t_hit_record	rec;

	interval.min = EPSILON;
	interval.max = vector_length(subtraction_op(&light->cord, ray->orig));
	while (world != NULL)
	{
		if (world->type == SPHERE)
		{
			if (hit_sphere((t_sphere *)world->object, interval, &rec, ray))
				return (FALSE);
		}
		else if (world->type == CYLINDER)
		{
			if (hit_cylinder((t_cylinder *)world->object, interval, &rec, ray))
				return (FALSE);
		}
		else if (world->type == PLANE)
		{
			if (hit_plane((t_plane *)world->object, interval, &rec, ray))
				return (FALSE);
		}
		world = world->next;
	}
	return (TRUE);
}

double	calculate_light(t_world_setup *world_setup, t_hit_record *rec,
		t_ray *ray)
{
	t_vec3			*light_dir;
	double			diffuse;
	double			specular;
	t_ray			light_ray;

	light_dir = unit_vector(subtraction_op(&world_setup->light->cord,
				rec->point));
	diffuse = max(0.0, dot_product(light_dir, rec->normal))
		* world_setup->light->brightness;
	if (diffuse == 0)
	{
		return (world_setup->ambient->lighting_ratio);
	}
	light_ray.orig = rec->point;
	light_ray.dir = light_dir;
	if (hit_light(world_setup->world, &light_ray, world_setup->light) == FALSE)
	{
		return (world_setup->ambient->lighting_ratio);
	}
	specular = max(0.0, dot_product(reflect_vec(light_dir, rec->normal),
				scalar_op(1.0, ray->dir))) * world_setup->light->brightness;
	return (diffuse + world_setup->ambient->lighting_ratio + specular);
}

/*double	calculate_light(t_world_setup *world_setup, t_hit_record *rec,
		t_ray *ray)
{
	t_vec3			*light_dir;
	double			diffuse;
	double			specular;
	t_ray			light_ray;
	T_POINT3		epsilon;

	epsilon.x = EPSILON * rec->normal->x;
	epsilon.y = EPSILON * rec->normal->y;
	epsilon.z = EPSILON * rec->normal->z;
	light_ray.orig = addition_op(rec->point, &epsilon);
	light_dir = unit_vector(subtraction_op(&world_setup->light->cord, light_ray.orig));
	light_ray.dir = light_dir;
	diffuse = max(0.0, dot_product(light_dir, rec->normal))
		* world_setup->light->brightness;
	if (diffuse > 0.0 && hit_light(world_setup->world, &light_ray) == FALSE)
		return (world_setup->ambient->lighting_ratio);
	specular = max(0.0, dot_product(reflect_vec(light_dir, rec->normal),
		scalar_op(1.0, ray->dir))) * world_setup->light->brightness;
	return (diffuse + world_setup->ambient->lighting_ratio + specular);
}*/

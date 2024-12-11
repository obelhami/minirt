#include "minirt.h"

void	set_normal_against_ray(t_ray *ray, t_hit_record *rec)
{
	if (dot_product(ray->dir, rec->normal) > 0.0)
		rec->normal = scalar_op(-1.0, rec->normal);
}

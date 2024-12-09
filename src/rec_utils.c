#include "minirt.h"

void	set_normal_against_ray(t_ray *ray, t_vec3 *normal)
{
	if (dot_product(ray->dir, normal) > 0.0)
		normal = scalar_op(-1.0, normal);
}

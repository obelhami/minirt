#include "minirt.h"

BOOL	hit_plane(t_plane *plane, t_interval interval, t_hit_record *rec,
		t_ray *ray)
{
	double	root;
	double	denominator;
	t_vec3	*diff;

	denominator = dot_product(&plane->normal_vec, ray->dir);
	if (denominator == 0)
		return (FALSE);
	diff = subtraction_op(&plane->point_cord, ray->orig);
	root = dot_product(diff, &plane->normal_vec) / denominator;
	if (root < interval.min || root >= interval.max)
		return (FALSE);
	rec->t = root;
	rec->point = ray_at(ray, rec->t);
	rec->normal = &plane->normal_vec;
	set_normal_against_ray(ray, rec);
	rec->color = &plane->color;
	return (TRUE);
}

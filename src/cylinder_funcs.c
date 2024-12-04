#include "minirt.h"

BOOL	adjust_endacps_inters(t_cylinder *cylinder, t_ray *ray, double *root)
{
	double		plane_root;
	T_POINT3	*base_center;
	t_vec3		*ctoi_vec;
	double		denominator;
	t_vec3		*dt_c;

	ctoi_vec = subtraction_op(ray_at(ray, *root), &cylinder->center);
	if (dot_product(ctoi_vec, &cylinder->axis_vec) < 0.0)
		base_center = addition_op(&cylinder->center,
				scalar_op(cylinder->height / 2, &cylinder->axis_vec));
	else
		base_center = subtraction_op(&cylinder->center,
				scalar_op(cylinder->height / 2, &cylinder->axis_vec));
	denominator = dot_product(&cylinder->axis_vec, ray->dir);
	if (denominator == 0)
		return (FALSE);
	plane_root = dot_product(&cylinder->axis_vec, base_center) / denominator;
	dt_c = subtraction_op(scalar_op(plane_root, ray->dir), base_center);
	if (dot_product(dt_c, dt_c) < pow(cylinder->radius, 2))
	{
		*root = plane_root;
		return (TRUE);
	}
	return (FALSE);
}

BOOL	hit_cylinder(t_cylinder *cylinder, t_interval interval,
		t_hit_record *rec, t_ray *ray)
{
	double			root;
	t_discriminant	discriminant;
	t_vec3			*cross_axis_dir;
	t_vec3			*cross_axis_ob;
	t_vec3			*ob;
	T_POINT3		*base_point;
	double			t;

	base_point = subtraction_op(&cylinder->center,
			scalar_op(cylinder->height / 2, &cylinder->axis_vec));
	cross_axis_dir = cross_product(&cylinder->axis_vec, ray->dir);
	ob = subtraction_op(base_point, ray->orig);
	cross_axis_ob = cross_product(&cylinder->axis_vec, ob);
	discriminant.a = dot_product(cross_axis_dir, cross_axis_dir);
	discriminant.b = -2 * dot_product(cross_axis_dir, cross_axis_ob);
	discriminant.c = dot_product(cross_axis_ob, cross_axis_ob)
		- pow(cylinder->radius, 2);
	discriminant.delta = pow(discriminant.b, 2)
		- 4 * discriminant.a * discriminant.c;
	if (discriminant.delta < 0)
		return (FALSE);
	root = (-discriminant.b - sqrt(discriminant.delta)) / (2.0 * discriminant.a);
	if (root <= interval.min || root >= interval.max)
		return (FALSE);
	t = dot_product(&cylinder->axis_vec,
			subtraction_op(scalar_op(root, ray->dir), ob));
	if (t < 0.0 || t > cylinder->height)
		return (FALSE);
	adjust_endacps_inters(cylinder, ray, &root);
	rec->t = root;
	rec->point = ray_at(ray, root);
	rec->color = &cylinder->color;
	//TODO: calculate normal vec at point
	return (TRUE);
}

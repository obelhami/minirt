#include "minirt.h"

double	root_at_body(t_cylinder *cylinder, t_interval interval, t_ray *ray)
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
		return (INFINITY);
	root = (-discriminant.b - sqrt(discriminant.delta)) / (2.0 * discriminant.a);
	if (root <= interval.min || root >= interval.max)
		return (INFINITY);
	t = dot_product(&cylinder->axis_vec,
			subtraction_op(scalar_op(root, ray->dir), ob));
	if (t < 0.0 || t > cylinder->height)
		return (INFINITY);
	return (root);
}

BOOL	close_tozero(double value)
{
	value = fabs(value); // TODO: create ft_fabs
	if (value < 1e-10)
		return (TRUE);
	return (FALSE);
}

double	root_at_encaps(t_cylinder *cylinder, t_interval interval, t_ray *ray,
		T_POINT3 *base_center)
{
	double	root;
	double	denominator;
	t_vec3	*co;
	t_vec3	*dt_plus_co;

	co = subtraction_op(ray->orig, base_center);
	denominator = dot_product(&cylinder->axis_vec, ray->dir);
	if (close_tozero(denominator))
		return (INFINITY);
	root = dot_product(&cylinder->axis_vec, co) / denominator;
	if (root < interval.min || root >= interval.max)
		return (INFINITY);
	dt_plus_co = addition_op(scalar_op(root, ray->dir), co);
	if (!close_tozero(dot_product(dt_plus_co, &cylinder->axis_vec)))
		return (INFINITY);
	if (dot_product(dt_plus_co, dt_plus_co) < pow(cylinder->radius, 2))
		return (root);
	return (INFINITY);
}

double	get_min(double value1, double value2, double value3)
{
	if (value1 < value2 && value1 < value3)
		return (value1);
	else if (value2 < value1 && value2 < value3)
		return (value2);
	else
		return (value3);
}

BOOL	hit_cylinder(t_cylinder *cylinder, t_interval interval,
		t_hit_record *rec, t_ray *ray)
{
	double	body_root;
	double	base1_root;
	double	base2_root;
	double	root;

	body_root = root_at_body(cylinder, interval, ray);
	base1_root = root_at_encaps(cylinder, interval, ray,
			subtraction_op(&cylinder->center,
			scalar_op(cylinder->height / 2, &cylinder->axis_vec)));
	base2_root = root_at_encaps(cylinder, interval, ray,
			addition_op(&cylinder->center,
			scalar_op(cylinder->height / 2, &cylinder->axis_vec)));
	root = get_min(body_root, base1_root, base2_root);
	if (root == INFINITY)
		return (FALSE);
	rec->t = root;
	rec->point = ray_at(ray, root);
	rec->color = &cylinder->color;
	//TODO: calculate normal vec at point
	return (TRUE);
}

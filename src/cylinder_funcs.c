#include "minirt.h"
# define INS_BODY
# define OUTS_BODY

void	get_body_rec(t_cylinder *cylinder, t_interval interval,
		t_ray *ray, T_POINT3 *base, t_hit_record *rec)
{
	t_discriminant	discriminant;
	t_vec3			*x;
	double			root;
	double			distance;

	x = subtraction_op(ray->orig, base);
	discriminant.a = dot_product(ray->dir, ray->dir)
			- pow(dot_product(ray->dir, &cylinder->axis_vec), 2);
	discriminant.b = 2 * (dot_product(ray->dir, x)
			- dot_product(ray->dir, &cylinder->axis_vec)
			* dot_product(x, &cylinder->axis_vec));
	discriminant.c = dot_product(x, x)
		- pow(dot_product(x, &cylinder->axis_vec), 2)
		- pow(cylinder->radius, 2);
	discriminant.delta = (discriminant.b * discriminant.b)
		- (4 * discriminant.a * discriminant.c);
	root = (-discriminant.b - sqrt(discriminant.delta)) / (2 * discriminant.a);
	if (root <= interval.min || root >= interval.max)
	{
		root = (-discriminant.b + sqrt(discriminant.delta))
			/ (2 * discriminant.a);
		if (root <= interval.min || root >= interval.max)
			return ;
	}
	distance = dot_product(&cylinder->axis_vec,
			addition_op(scalar_op(root, ray->dir), x));
	if (distance < 0.0 || distance > cylinder->height)
		return ;
	rec->t = root;
	rec->point = ray_at(ray, root);
	rec->normal = subtraction_op(scalar_op(root, ray->dir),
			scalar_op(distance, &cylinder->axis_vec));
	rec->normal = unit_vector(subtraction_op(rec->normal, base));
	set_normal_against_ray(ray, rec);
}

void	get_base_rec(t_cylinder *cylinder, t_interval interval, t_ray *ray,
		T_POINT3 *base, t_hit_record *rec)
{
	double	root;
	t_vec3	*x;
	t_vec3	*holder;

	x = subtraction_op(ray->orig, base);
	root = dot_product(&cylinder->axis_vec, base)
		/ dot_product(&cylinder->axis_vec, ray->dir);
	if (root <= interval.min || root >= interval.max)
		return ;
	holder = addition_op(scalar_op(root, ray->dir), x);
	if (!closeto_zero(dot_product(&cylinder->axis_vec, holder)))
			return ;
	if (dot_product(holder, holder) < pow(cylinder->radius, 2))
	{
		rec->t = root;
		rec->point = ray_at(ray, root);
	}
}

t_hit_record	*get_valid_rec(t_hit_record *rec1, t_hit_record *rec2,
		t_hit_record *rec3)
{
	if (rec1->t < rec2->t && rec1->t < rec3->t)
		return (rec1);
	else if (rec2->t < rec1->t && rec2->t < rec3->t)
		return (rec2);
	else
		return (rec3);
}

BOOL	hit_cylinder(t_cylinder *cylinder, t_interval interval,
		t_hit_record *rec, t_ray * ray)
{
	t_hit_record	body_rec;
	t_hit_record	upperbase_rec;
	t_hit_record	lowerbase_rec;
	T_POINT3		*upper_base; //TODO: add *_base to the cylinder struct
	T_POINT3		*lower_base;
	t_hit_record	*temp_rec;

	body_rec = (t_hit_record){.t = INFINITY};
	upperbase_rec = (t_hit_record){.t = INFINITY, .normal = &cylinder->axis_vec};
	lowerbase_rec = (t_hit_record){.t = INFINITY, .normal = &cylinder->axis_vec};
	set_normal_against_ray(ray, &lowerbase_rec);
	set_normal_against_ray(ray, &upperbase_rec);
	get_bases_centers(cylinder, &upper_base, &lower_base);
	get_body_rec(cylinder, interval, ray, lower_base, &body_rec);
	get_base_rec(cylinder, interval, ray, upper_base, &upperbase_rec);
	get_base_rec(cylinder, interval, ray, lower_base, &lowerbase_rec);
	temp_rec = get_valid_rec(&body_rec, &upperbase_rec, &lowerbase_rec);
	if (temp_rec->t == INFINITY)
		return (FALSE);
	rec->t = temp_rec->t;
	rec->point = temp_rec->point;
	rec->normal = temp_rec->normal;
	rec->color = &cylinder->color;
	return (TRUE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajawad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:09:12 by ajawad            #+#    #+#             */
/*   Updated: 2024/12/29 06:06:07 by ajawad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vec3	*get_normal(t_cylinder *cylinder, t_ray *ray, double root,
		double distance)
{
	t_vec3	*normal;

	normal = unit_vector(subtraction_op(subtraction_op(scalar_op(root,
						ray->dir), scalar_op(distance, &cylinder->axis_vec)),
				cylinder->lower_base));
	if (dot_product(ray->dir, normal) > 0.0)
		normal = scalar_op(-1.0, normal);
	return (normal);
}

void	get_body_rec(t_cylinder *cylinder, t_interval interval, t_ray *ray,
		t_hit_record *rec)
{
	t_discriminant	*eq;
	t_vec3			*x;
	double			root;
	double			distance;

	x = subtraction_op(ray->orig, cylinder->lower_base);
	eq = solve_quadratic_eq(cylinder, ray, x);
	if (eq->delta < 0)
		return ;
	root = (-eq->b - sqrt(eq->delta)) / (2 * eq->a);
	if (root <= interval.min || root >= interval.max)
	{
		root = (-eq->b + sqrt(eq->delta)) / (2 * eq->a);
		if (root <= interval.min || root >= interval.max)
			return ;
	}
	distance = dot_product(&cylinder->axis_vec,
			addition_op(scalar_op(root, ray->dir), x));
	if (distance < 0.0 || distance > cylinder->height)
		return ;
	rec->t = root;
	rec->point = ray_at(ray, root);
	rec->normal = get_normal(cylinder, ray, root, distance);
}

void	get_base_rec(t_cylinder *cylinder, t_interval interval, t_ray *ray,
		t_hit_record *rec)
{
	double		root;
	t_vec3		*co;
	t_vec3		*holder;
	T_POINT3	*base;
	static int	base_indicator;

	base = NULL;
	if (base_indicator == UPPER_BASE)
		base = cylinder->upper_base;
	else if (base_indicator == LOWER_BASE)
		base = cylinder->lower_base;
	co = subtraction_op(ray->orig, base);
	root = dot_product(&cylinder->axis_vec, base)
		/ dot_product(&cylinder->axis_vec, ray->dir);
	if (root <= interval.min || root >= interval.max)
		return ;
	holder = addition_op(scalar_op(root, ray->dir), co);
	if (!closeto_zero(dot_product(&cylinder->axis_vec, holder)))
		return ;
	if (dot_product(holder, holder) < pow(cylinder->radius, 2))
	{
		rec->t = root;
		rec->point = ray_at(ray, root);
	}
	base_indicator = (base_indicator + 1) % 2;
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

int	hit_cylinder(void *ptr, t_interval interval,
		t_hit_record *rec, t_ray *ray)
{
	t_cylinder		*cylinder;
	t_hit_record	body_rec;
	t_hit_record	upperbase_rec;
	t_hit_record	lowerbase_rec;
	t_hit_record	*temp_rec;

	cylinder = (t_cylinder *)ptr;
	body_rec = (t_hit_record){.t = INFINITY};
	upperbase_rec = (t_hit_record){.t = INFINITY,
		.normal = &cylinder->axis_vec};
	lowerbase_rec = (t_hit_record){.t = INFINITY,
		.normal = &cylinder->axis_vec};
	set_normal_against_ray(ray, &lowerbase_rec);
	set_normal_against_ray(ray, &upperbase_rec);
	get_body_rec(cylinder, interval, ray, &body_rec);
	get_base_rec(cylinder, interval, ray, &upperbase_rec);
	get_base_rec(cylinder, interval, ray, &lowerbase_rec);
	temp_rec = get_valid_rec(&body_rec, &upperbase_rec, &lowerbase_rec);
	if (temp_rec->t == INFINITY)
		return (FALSE);
	rec->t = temp_rec->t;
	rec->point = temp_rec->point;
	rec->normal = temp_rec->normal;
	rec->color = &cylinder->color;
	return (TRUE);
}

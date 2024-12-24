/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajawad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:09:12 by ajawad            #+#    #+#             */
/*   Updated: 2024/12/24 14:11:23 by ajawad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_discriminant	*solve_quadratic_eq(t_cylinder *cylinder, t_ray *ray,
		T_POINT3 *co)
{
	t_discriminant	*eq;

	eq = malloc(sizeof(t_discriminant));
	if (eq == NULL)
		return (NULL);
	eq->a = dot_product(ray->dir, ray->dir)
		- pow(dot_product(ray->dir, &cylinder->axis_vec), 2);
	eq->b = 2 * (dot_product(ray->dir, co)
			- dot_product(ray->dir, &cylinder->axis_vec)
			* dot_product(co, &cylinder->axis_vec));
	eq->c = dot_product(co, co)
		- pow(dot_product(co, &cylinder->axis_vec), 2)
		- pow(cylinder->radius, 2);
	eq->delta = (eq->b * eq->b) - (4 * eq->a * eq->c);
	return (eq);
}

void	get_body_rec(t_cylinder *cylinder, t_interval interval,
		t_ray *ray, T_POINT3 *base, t_hit_record *rec)
{
	t_discriminant	*eq;
	t_vec3			*x;
	double			root;
	double			distance;

	x = subtraction_op(ray->orig, base);
	eq = solve_quadratic_eq(cylinder, ray, x);
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
	rec->normal = subtraction_op(scalar_op(root, ray->dir),
			scalar_op(distance, &cylinder->axis_vec));
	rec->normal = unit_vector(subtraction_op(rec->normal, base));
	set_normal_against_ray(ray, rec);
}

void	get_base_rec(t_cylinder *cylinder, t_interval interval, t_ray *ray,
		T_POINT3 *base, t_hit_record *rec)
{
	double	root;
	t_vec3	*co;
	t_vec3	*holder;

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

BOOL	hit_cylinder(void *ptr, t_interval interval,
		t_hit_record *rec, t_ray *ray)
{
	t_cylinder		*cylinder;
	t_hit_record	body_rec;
	t_hit_record	upperbase_rec;
	t_hit_record	lowerbase_rec;
	t_hit_record	*temp_rec;

	cylinder = (t_cylinder *)ptr;
	body_rec = (t_hit_record){.t = INFINITY};
	upperbase_rec = H_REC{.t = INFINITY, .normal = &cylinder->axis_vec};
	lowerbase_rec = H_REC{.t = INFINITY, .normal = &cylinder->axis_vec};
	set_normal_against_ray(ray, &lowerbase_rec);
	set_normal_against_ray(ray, &upperbase_rec);
	get_body_rec(cylinder, interval, ray, cylinder->lower_base, &body_rec);
	get_base_rec(cylinder, interval, ray, cylinder->upper_base, &upperbase_rec);
	get_base_rec(cylinder, interval, ray, cylinder->lower_base, &lowerbase_rec);
	temp_rec = get_valid_rec(&body_rec, &upperbase_rec, &lowerbase_rec);
	if (temp_rec->t == INFINITY)
		return (FALSE);
	rec->t = temp_rec->t;
	rec->point = temp_rec->point;
	rec->normal = temp_rec->normal;
	rec->color = &cylinder->color;
	return (TRUE);
}

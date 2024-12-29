/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_funcs_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajawad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:41:59 by ajawad            #+#    #+#             */
/*   Updated: 2024/12/29 21:18:41 by ajawad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_bases_centers(t_cylinder *cylinder)
{
	T_POINT3	*base1;
	T_POINT3	*base2;

	base1 = addition_op(&cylinder->center,
			scalar_op(cylinder->height / 2, &cylinder->axis_vec));
	base2 = subtraction_op(&cylinder->center,
			scalar_op(cylinder->height / 2, &cylinder->axis_vec));
	if (dot_product(subtraction_op(&cylinder->center, base1),
			&cylinder->axis_vec) > 0.0)
	{
		cylinder->lower_base = base1;
		cylinder->upper_base = base2;
	}
	else
	{
		cylinder->lower_base = base2;
		cylinder->upper_base = base1;
	}
}

double	ft_fabs(double value)
{
	if (value < 0)
		return (-value);
	return (value);
}

inline int	closeto_zero(double value)
{
	value = ft_fabs(value);
	if (value < 1e-10)
		return (TRUE);
	return (FALSE);
}

t_discriminant	*solve_quadratic_eq(t_cylinder *cylinder, t_ray *ray,
		T_POINT3 *co)
{
	t_discriminant	*eq;

	eq = alloc(sizeof(t_discriminant));
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajawad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:43:55 by ajawad            #+#    #+#             */
/*   Updated: 2024/12/27 22:08:04 by ajawad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

BOOL	hit_plane(void *ptr, t_interval interval, t_hit_record *rec,
		t_ray *ray)
{
	t_plane	*plane;
	double	root;
	double	denominator;
	t_vec3	*diff;

	plane = (t_plane *)ptr;
	denominator = dot_product(&plane->normal_vec, ray->dir);
	if (closeto_zero(denominator))
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajawad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:18:12 by ajawad            #+#    #+#             */
/*   Updated: 2024/12/29 21:19:26 by ajawad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

inline T_POINT3	*ray_at(t_ray *ray, double t)
{
	return (addition_op(ray->orig, scalar_op(t, ray->dir)));
}

inline void	fill_vec3(t_vec3 *vec, double x, double y, double z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

inline t_vec3	*create_vec3(double x, double y, double z)
{
	t_vec3	*v;

	v = alloc(sizeof(t_vec3));
	v->x = x;
	v->y = y;
	v->z = z;
	return (v);
}

inline t_vec3	*reflect_vec(t_vec3 *incident_vec, t_vec3 *surface_normal)
{
	t_vec3	*reflected_vec;

	reflected_vec = subtraction_op(incident_vec,
			scalar_op(-2.0 * dot_product(incident_vec, surface_normal),
				surface_normal));
	return (reflected_vec);
}

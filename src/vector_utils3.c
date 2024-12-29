/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajawad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:14:52 by ajawad            #+#    #+#             */
/*   Updated: 2024/12/29 21:19:54 by ajawad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

inline double	dot_product(t_vec3 *v, t_vec3 *u)
{
	return ((v->x * u->x) + (v->y * u->y) + (v->z * u->z));
}

inline t_vec3	*cross_product(t_vec3 *v, t_vec3 *u)
{
	t_vec3	*cross_product_vec;

	cross_product_vec = alloc(sizeof(t_vec3));
	cross_product_vec->x = (v->y * u->z) - (v->z * u->y);
	cross_product_vec->y = (v->z * u->x) - (v->x * u->z);
	cross_product_vec->z = (v->x * v->y) - (v->y * u->x);
	return (cross_product_vec);
}

inline double	vector_length_squared(t_vec3 *vec)
{
	double	length_squared;

	length_squared = (vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z);
	return (length_squared);
}

inline double	vector_length(t_vec3 *vec)
{
	return (sqrt(vector_length_squared(vec)));
}

inline t_vec3	*unit_vector(t_vec3 *vector)
{
	t_vec3	*unit_vector;

	unit_vector = division_op(vector, vector_length(vector));
	return (unit_vector);
}

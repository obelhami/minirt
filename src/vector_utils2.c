/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajawad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:13:47 by ajawad            #+#    #+#             */
/*   Updated: 2024/12/29 21:19:45 by ajawad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

inline t_vec3	*scalar_op(double t, t_vec3 *vec)
{
	t_vec3	*scaled_vec;

	scaled_vec = alloc(sizeof(t_vec3));
	scaled_vec->x = t * vec->x;
	scaled_vec->y = t * vec->y;
	scaled_vec->z = t * vec->z;
	return (scaled_vec);
}

inline t_vec3	*division_op(t_vec3 *v, double t)
{
	return (scalar_op(1 / t, v));
}

inline t_vec3	*addition_op(t_vec3 *v, t_vec3 *u)
{
	t_vec3	*resultant_vec;

	resultant_vec = alloc(sizeof(t_vec3));
	resultant_vec->x = v->x + u->x;
	resultant_vec->y = v->y + u->y;
	resultant_vec->z = v->z + u->z;
	return (resultant_vec);
}

inline t_vec3	*subtraction_op(t_vec3 *v, t_vec3 *u)
{
	t_vec3	*difference_vec;

	difference_vec = alloc(sizeof(t_vec3));
	difference_vec->x = v->x - u->x;
	difference_vec->y = v->y - u->y;
	difference_vec->z = v->z - u->z;
	return (difference_vec);
}

inline t_vec3	*hadamard_product(t_vec3 *v, t_vec3 *u)
{
	t_vec3	*hadamard_product_vec;

	hadamard_product_vec = alloc(sizeof(t_vec3));
	hadamard_product_vec->x = v->x * u->x;
	hadamard_product_vec->y = v->y * u->y;
	hadamard_product_vec->z = v->z * u->z;
	return (hadamard_product_vec);
}

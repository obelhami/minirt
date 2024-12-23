/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajawad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:46:59 by ajawad            #+#    #+#             */
/*   Updated: 2024/12/13 14:47:00 by ajawad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

inline void	set_normal_against_ray(t_ray *ray, t_hit_record *rec)
{
	if (dot_product(ray->dir, rec->normal) > 0.0)
		rec->normal = scalar_op(-1.0, rec->normal);
}

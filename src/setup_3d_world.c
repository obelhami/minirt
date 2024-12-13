/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_3d_world.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajawad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:47:56 by ajawad            #+#    #+#             */
/*   Updated: 2024/12/13 14:51:19 by ajawad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	setup_viewport_dimentions(t_windata *win, t_world_setup *world_setup,
		double focal_length)
{
	double		tan_theta;

	tan_theta = tan(degrees_to_radians(world_setup->camera->hfov) / 2);
	world_setup->viewport_width = 2 * tan_theta * focal_length;
	world_setup->viewport_height = world_setup->viewport_width
		/ ((double)win->width / win->height);
}

int	setup_3d_world(t_windata *win, t_world_setup *world_sp)
{
	T_POINT3	*v_upper_left;
	double		focal_length;
	t_vec3		*w;
	t_vec3		*u;
	t_vec3		*v;

	focal_length = 1.0;
	setup_viewport_dimentions(win, world_sp, focal_length);
	w = &world_sp->camera->orientation_vec;
	u = unit_vector(cross_product(create_vec3(0, 1.0, 0), w));
	v = cross_product(w, u);
	world_sp->viewport_u = scalar_op(world_sp->viewport_width, u);
	world_sp->viewport_v = scalar_op(world_sp->viewport_height * -1.0, v);
	world_sp->delta_u = division_op(world_sp->viewport_u, win->width);
	world_sp->delta_v = division_op(world_sp->viewport_v, win->height);
	v_upper_left = subtraction_op(&world_sp->camera->cord,
			scalar_op(focal_length, w));
	v_upper_left = subtraction_op(v_upper_left,
			division_op(world_sp->viewport_u, 2));
	v_upper_left = subtraction_op(v_upper_left,
			division_op(world_sp->viewport_v, 2));
	world_sp->pixel00_loc = addition_op(v_upper_left,
			scalar_op(0.5, addition_op(world_sp->delta_v, world_sp->delta_u)));
	world_sp->samples_per_pixel = 10;
	return (0);
}

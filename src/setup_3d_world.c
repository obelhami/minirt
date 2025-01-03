/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_3d_world.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajawad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:07:30 by ajawad            #+#    #+#             */
/*   Updated: 2024/12/27 17:51:04 by ajawad           ###   ########.fr       */
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

int	calculate_pixel00_loc(t_world_setup *world_setup, t_vec3 *w,
		double focal_length)
{
	T_POINT3	*v_upper_left;

	v_upper_left = subtraction_op(&world_setup->camera->cord,
			scalar_op(focal_length, w));
	v_upper_left = subtraction_op(v_upper_left,
			division_op(world_setup->viewport_u, 2));
	v_upper_left = subtraction_op(v_upper_left,
			division_op(world_setup->viewport_v, 2));
	world_setup->pixel00_loc = addition_op(v_upper_left,
			scalar_op(2.5, world_setup->delta_u));
	world_setup->pixel00_loc = addition_op(world_setup->pixel00_loc,
			scalar_op(2.5, world_setup->delta_v));
	return (0);
}

int	setup_3d_world(t_windata *win, t_world_setup *world_setup)
{
	double		focal_length;
	t_vec3		*w;
	t_vec3		*u;
	t_vec3		*v;

	focal_length = 1.0;
	setup_viewport_dimentions(win, world_setup, focal_length);
	w = scalar_op(-1.0, &world_setup->camera->orientation_vec);
	u = unit_vector(cross_product(create_vec3(0, 1.0, 0), w));
	v = cross_product(w, u);
	world_setup->viewport_u = scalar_op(world_setup->viewport_width, u);
	world_setup->viewport_v = scalar_op(world_setup->viewport_height * -1.0, v);
	world_setup->delta_u = division_op(world_setup->viewport_u, win->width);
	world_setup->delta_v = division_op(world_setup->viewport_v, win->height);
	calculate_pixel00_loc(world_setup, w, focal_length);
	world_setup->samples_per_pixel = 1;
	return (0);
}

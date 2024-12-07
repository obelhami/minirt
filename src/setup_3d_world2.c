#include "minirt.h"

int	setup_3d_world(t_windata *win, t_world_setup *world_setup)
{
	double		tan_theta;
	T_POINT3	*v_upper_left;

	world_setup->focal_length = 1.0;
	tan_theta = tan(degrees_to_radians(world_setup->camera->hfov) / 2);
	world_setup->viewport_width = 2 * tan_theta * world_setup->focal_length;
	world_setup->viewport_height = world_setup->viewport_width
			/ ((double)win->width / win->height);
	fill_vec3(&world_setup->viewport_u, world_setup->viewport_width, 0.0, 0.0);
	fill_vec3(&world_setup->viewport_v, 0.0, world_setup->viewport_height, 0.0);
	world_setup->delta_u = division_op(&world_setup->viewport_u, win->width);
	world_setup->delta_v = division_op(&world_setup->viewport_v, win->height);
	v_upper_left = create_vec3(
			world_setup->camera->cord.x - (world_setup->viewport_u.x / 2),
			world_setup->camera->cord.y - (world_setup->viewport_v.y / 2),
			world_setup->camera->cord.z - world_setup->focal_length);
	world_setup->pixel00_loc = create_vec3(
			v_upper_left->x + (0.5 * world_setup->delta_u->x),
			v_upper_left->y + (0.5 * world_setup->delta_v->y),
			v_upper_left->z);
	world_setup->samples_per_pixel = 10;
	return (0);
}

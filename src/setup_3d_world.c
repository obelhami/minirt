#include "minirt.h"

int	setup_3d_world(t_windata *win, t_world_setup *world_setup)
{
	double		tan_theta;
	T_POINT3	*v_upper_left;
	t_vec3		*w;
	t_vec3		*u;
	t_vec3		*v;

	world_setup->focal_length = 1.0;
	tan_theta = tan(degrees_to_radians(world_setup->camera->hfov) / 2);
	world_setup->viewport_width = 2 * tan_theta * world_setup->focal_length;
	world_setup->viewport_height = world_setup->viewport_width
			/ ((double)win->width / win->height);

	w = &world_setup->camera->orientation_vec;
	u = unit_vector(cross_product(create_vec3(0, 1.0, 0), w));
	v = cross_product(w, u);

	world_setup->viewport_u = scalar_op(world_setup->viewport_width, u);
	world_setup->viewport_v = scalar_op(world_setup->viewport_height * -1.0, v);

	world_setup->delta_u = division_op(world_setup->viewport_u, win->width);
	world_setup->delta_v = division_op(world_setup->viewport_v, win->height);

	v_upper_left = subtraction_op(&world_setup->camera->cord,
			scalar_op(world_setup->focal_length, w));
	v_upper_left = subtraction_op(v_upper_left,
			division_op(world_setup->viewport_u, 2));
	v_upper_left = subtraction_op(v_upper_left,
			division_op(world_setup->viewport_v, 2));

	world_setup->pixel00_loc = addition_op(v_upper_left, 
		scalar_op(0.5, addition_op(world_setup->delta_v, world_setup->delta_u)));

	world_setup->samples_per_pixel = 10;
	return (0);
}
	

/*
printf("width: %f\n", world_setup->viewport_width);
	printf("height: %f\n", world_setup->viewport_height);
	printf("w: x=%f, y=%f, z=%f\n", w->x, w->y, w->z);
	printf("u: x=%f, y=%f, z=%f\n", u->x, u->y, u->z);
	printf("v: x=%f, y=%f, z=%f\n", v->x, v->y, v->z);
	printf("v_u: x=%f, y=%f, z=%f\n", world_setup->viewport_u->x,
			world_setup->viewport_u->y, world_setup->viewport_u->z);
	printf("v_v: x=%f, y=%f, z=%f\n", world_setup->viewport_v->x,
			world_setup->viewport_v->y, world_setup->viewport_v->z);
	printf("d_u: x=%f, y=%f, z=%f\n", world_setup->delta_u->x,
			world_setup->delta_u->y, world_setup->delta_u->z);
	printf("d_u: x=%f, y=%f, z=%f\n", world_setup->delta_v->x,
			world_setup->delta_v->y, world_setup->delta_v->z);
	printf("upper_left: x=%f, y=%f, z=%f\n", v_upper_left->x, v_upper_left->y,
			v_upper_left->z);
	printf("pixel00: x=%f, y=%f, z=%f\n", world_setup->pixel00_loc->x,
			world_setup->pixel00_loc->y, world_setup->pixel00_loc->z);

*/

#include "minirt.h"

double	clamp(t_interval *interval, double var)
{
	if (var < interval->min)
		return (interval->min);
	else if (var > interval->max)
		return (interval->max);
	else
		return (var);
}

void	pixel_put_in_img(t_img *img, int x, int y, t_rgb *color)
{
	char		*dest;
	int			rgb;

	rgb = color->r << 16
		| color->g << 8
		| color->b;
	dest = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dest = rgb;
}

t_rgb	*ray_color(t_ray *ray, t_object_container *world)
{
	t_rgb			*color;
	t_interval		interval;
	t_hit_record	rec;

	color = malloc(sizeof(t_rgb));
	if (color == NULL)
		return (NULL);
	interval.min = 0;
	interval.max = INFINITY;
	if (hit_any_object(world, interval, &rec, ray))
	{
		return (rec.color);
	}
	color->r = 255;
	color->g = 255;
	color->b = 255;
	return (color);
}

int	render(t_windata *win, t_world_setup *world_setup)
{
	int			idx;
	int			jdx;
	T_POINT3	*pixel_center;
	t_rgb		*pixel_color;
	t_ray		ray;

	idx = 0;
	while (idx < win->height)
	{
		jdx = 0;
		while (jdx < win->width)
		{
			pixel_center = addition_op(world_setup->pixel00_loc,
					addition_op(scalar_op(jdx, world_setup->delta_u),
							scalar_op(idx, world_setup->delta_v)));
			ray.orig = &world_setup->v_camera;
			ray.dir = subtraction_op(pixel_center, &world_setup->v_camera);
			pixel_color = ray_color(&ray, world_setup->world);
			pixel_put_in_img(&win->img, jdx, idx, pixel_color);
			jdx++;
		}
		idx++;
	}
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->img.img, 0, 0);
	return (0);
}

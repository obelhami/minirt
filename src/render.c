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
	t_interval	interval;

	interval.min = 0.000;
	interval.max = 0.999;
	rgb = (int)(256 * clamp(&interval, color->red)) << 16
		| (int)(256 * clamp(&interval, color->green)) << 8
		| (int)(256 * clamp(&interval, color->blue));
	dest = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dest = rgb;
}

int	hit_sphere(t_sphere *sphere, t_ray *ray)
{
	double	a;
	double	b;
	double	c;
	double	delta;
	t_vec3	*oc;

	oc = subtraction_op(&sphere->cord, ray->orig);
	a = dot_product(ray->dir, ray->dir);
	b = -2.0 * dot_product(ray->dir, oc);
	c = dot_product(oc, oc) - (sphere->diameter * sphere->diameter);
	delta = (b * b) - (4 * a * c);
	if (delta >= 0)
		return (1);
	else
		return (0);
}

t_rgb	*ray_color(t_ray *ray)
{
	t_rgb		*rgb;
	t_sphere	sphere;

	(void)ray;
	rgb = malloc(sizeof(t_rgb));
	if (rgb == NULL)
		return (NULL);
	fill_vec3(&sphere.cord, 0.0, 0.0, -1.0);
	sphere.diameter = 0.5;
	if (hit_sphere(&sphere, ray))
	{
		rgb->red = 0;
		rgb->green = 255;
		rgb->blue = 0;
		return (rgb);
	}
	rgb->red = 255;
	rgb->green = 255;
	rgb->blue = 255;
	return (rgb);
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
			pixel_color = ray_color(&ray);
			pixel_put_in_img(&win->img, jdx, idx, pixel_color);
			jdx++;
		}
		idx++;
	}
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->img.img, 0, 0);
	return (0);
}

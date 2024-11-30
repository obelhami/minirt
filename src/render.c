#include "minirt.h"

int	clamp(t_interval *interval, int var)
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

	interval.min = 0.0;
	interval.max = 255.0;
	rgb = clamp(&interval, color->r) << 16
		| clamp(&interval, color->g) << 8
		| clamp(&interval, color->b);
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
		return (rec.color);
	color->r = 255;
	color->g = 255;
	color->b = 255;
	return (color);
}

t_rgb	*colors_addition(t_rgb *color1, t_rgb *color2)
{
	t_rgb	*resulted_color;

	resulted_color = malloc(sizeof(t_rgb));
	if (resulted_color == NULL)
		return (NULL);
	resulted_color->r = color1->r + color2->r;
	resulted_color->g = color1->g + color2->g;
	resulted_color->b = color1->b + color2->b;
	return (resulted_color);
}

t_rgb	*scale_color(double scalar, t_rgb *color)
{
	t_rgb	*resulted_color;

	resulted_color = malloc(sizeof(t_rgb));
	if (resulted_color == NULL)
		return (NULL);
	resulted_color->r = scalar * color->r;
	resulted_color->g = scalar * color->g;
	resulted_color->b = scalar * color->b;
	return (resulted_color);
}

t_ray	*get_ray(int jdx, int idx, t_world_setup *world_setup)
{
	t_vec3		*offset;
	T_POINT3	*pixel_sample;
	t_ray		*ray;
	
	offset = create_vec3(random_double() - 0.5, random_double() - 0.5, 0);
	pixel_sample = addition_op(world_setup->pixel00_loc, addition_op(
				scalar_op(jdx + offset->x, world_setup->delta_u),
				scalar_op(idx + offset->y, world_setup->delta_v)));
	ray = malloc(sizeof(t_ray));
	if (ray == NULL)
		return (NULL);
	ray->orig = &world_setup->camera->cord;
	ray->dir = subtraction_op(pixel_sample, ray->orig);
	return (ray);
}

int	render(t_windata *win, t_world_setup *world_setup)
{
	int			idx;
	int			jdx;
	int			sample;
	t_rgb		*pixel_color;
	t_ray		*ray;

	idx = 0;
	
	while (idx < win->height)
	{
		jdx = 0;
		while (jdx < win->width)
		{
			pixel_color = malloc(sizeof(t_rgb));
			if (pixel_color == NULL)
				return (-1);
			pixel_color->r = 0;
			pixel_color->g = 0;
			pixel_color->b = 0;
			sample = 0;
			while (sample < world_setup->samples_per_pixel)
			{
				ray = get_ray(jdx, idx, world_setup);
				pixel_color = colors_addition(pixel_color,
						ray_color(ray, world_setup->world));
				sample++;
			}
			pixel_put_in_img(&win->img, jdx, idx, scale_color(
						1.0 / world_setup->samples_per_pixel, pixel_color));
			jdx++;
		}
		idx++;
	}
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->img.img, 0, 0);
	return (0);
}

/*	pixel_center = addition_op(world_setup->pixel00_loc,
					addition_op(scalar_op(jdx, world_setup->delta_u),
							scalar_op(idx, world_setup->delta_v)));
		ray.orig = &world_setup->v_camera;
			ray.dir = subtraction_op(pixel_center, &world_setup->v_camera);
			pixel_color = ray_color(&ray, world_setup->world);
			pixel_put_in_img(&win->img, jdx, idx, pixel_color);*/


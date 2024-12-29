/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajawad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:47:13 by ajawad            #+#    #+#             */
/*   Updated: 2024/12/29 21:20:53 by ajawad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	colors_addition_cstm(t_rgb *color1, t_rgb *color2)
{
	color1->r = color1->r + color2->r;
	color1->g = color1->g + color2->g;
	color1->b = color1->b + color2->b;
}

t_rgb	*create_color(int r, int g, int b)
{
	t_rgb	*color;

	color = alloc(sizeof(t_rgb));
	color->r = r;
	color->g = g;
	color->b = b;
	return (color);
}

t_rgb	*get_pixel_color(t_world_setup *world_setup, t_ray *ray, int x, int y)
{
	t_rgb	pixel_color;
	int		sample;

	sample = 0;
	pixel_color = (t_rgb){.r = 0, .g = 0, .b = 0};
	while (sample < world_setup->samples_per_pixel)
	{
		ray = get_ray(x, y, world_setup);
		colors_addition_cstm(&pixel_color, ray_color(world_setup, ray));
		sample++;
	}
	return (create_color(pixel_color.r, pixel_color.g, pixel_color.b));
}

int	render(t_windata *win, t_world_setup *world_setup)
{
	int			idx;
	int			jdx;
	t_rgb		*pixel_color;
	t_ray		ray;
	int			rgb;

	idx = 0;
	while (idx < win->height)
	{
		jdx = 0;
		while (jdx < win->width)
		{
			pixel_color = get_pixel_color(world_setup, &ray, jdx, idx);
			rgb = clamp(0.0, 255.0, pixel_color->r) << 16
				| clamp(0.0, 255.0, pixel_color->g) << 8
				| clamp(0.0, 255.0, pixel_color->b);
			mlx_pixel_put(win->mlx, win->mlx_win, jdx, idx, rgb);
			jdx++;
		}
		idx++;
	}
	return (0);
}

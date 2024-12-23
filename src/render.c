/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajawad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:47:13 by ajawad            #+#    #+#             */
/*   Updated: 2024/12/13 14:47:47 by ajawad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	pixel_put_in_img(t_windata *win, int x, int y, t_rgb *color)
{
	int			rgb;

	rgb = clamp(0.0, 255.0, color->r) << 16
		| clamp(0.0, 255.0, color->g) << 8
		| clamp(0.0, 255.0, color->b);
	mlx_pixel_put(win->mlx, win->mlx_win, x, y, rgb);
}

t_rgb	*get_pixel_color(t_world_setup *world_setup, t_ray *ray, int x, int y)
{
	t_rgb	*pixel_color;
	int		sample;

	sample = 0;
	pixel_color = malloc(sizeof(t_rgb));
	if (pixel_color == NULL)
		return (NULL);
	pixel_color->r = 0;
	pixel_color->g = 0;
	pixel_color->b = 0;
	while (sample < world_setup->samples_per_pixel)
	{
		ray = get_ray(x, y, world_setup);
		pixel_color = colors_addition(pixel_color,
				ray_color(world_setup, ray));
		sample++;
	}
	return (pixel_color);
}

int	render(t_windata *win, t_world_setup *world_setup)
{
	int			idx;
	int			jdx;
	t_rgb		*pixel_color;
	t_ray		ray;

	idx = 0;
	while (idx < win->height)
	{
		jdx = 0;
		while (jdx < win->width)
		{
			pixel_color = get_pixel_color(world_setup, &ray, jdx, idx);
			if (pixel_color == NULL)
				return (-1);
			pixel_put_in_img(win, jdx, idx, scale_color(
					1.0 / world_setup->samples_per_pixel, pixel_color));
			jdx++;
		}
		idx++;
	}
	return (0);
}

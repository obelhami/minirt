/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajawad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:55:21 by ajawad            #+#    #+#             */
/*   Updated: 2024/12/29 21:14:42 by ajawad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	catch_keypress(int keycode, void *param)
{
	(void)param;
	if (keycode == ESC)
		garbage_collector();
	return (0);
}

int	destroy_window(void *ptr)
{
	(void)ptr;
	garbage_collector();
	return (0);
}

int	create_window(t_windata *window_data)
{
	window_data->aspect_ratio = 16.0 / 9.0;
	window_data->width = 1500;
	window_data->height = (int)(window_data->width / window_data->aspect_ratio);
	if (window_data->height < 1)
		window_data->height = 1;
	window_data->mlx = mlx_init();
	window_data->mlx_win = mlx_new_window(window_data->mlx, window_data->width,
			window_data->height, "Minirt");
	mlx_hook(window_data->mlx_win, 17, 0, destroy_window, NULL);
	mlx_hook(window_data->mlx_win, 2, 1L << 0, catch_keypress, window_data);
	return (0);
}

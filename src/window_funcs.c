#include "minirt.h"

int	catch_keypress(int keycode, void *param)
{
	/*TODO: free*/
	(void)param;
	if (keycode == ESC)
		exit(1);
	return (0);
}

int	destroy_window(void *ptr)
{
	/*TODO: free*/
	(void)ptr;
	exit(1);
	return (0);
}

int	create_image(t_windata *win_data)
{
	win_data->img.img = mlx_new_image(win_data->mlx,
			win_data->width, win_data->height);
	win_data->img.addr = mlx_get_data_addr(win_data->img.img,
			&win_data->img.bits_per_pixel, &win_data->img.line_length,
			&win_data->img.endian);
	return (1);
}

int	create_window(t_windata *window_data)
{
	window_data->aspect_ratio = 16.0 / 9.0;
	window_data->width = 1500;
	window_data->height = (int)(window_data->width / window_data->aspect_ratio);
	if (window_data->height <  1)
		window_data->height = 1;
	window_data->mlx = mlx_init();
	window_data->mlx_win = mlx_new_window(window_data->mlx, window_data->width,
			window_data->height, "Minirt");
	mlx_hook(window_data->mlx_win, 17, 0, destroy_window, NULL);
	mlx_hook(window_data->mlx_win, 2,1L<<0, catch_keypress, window_data);
	return (0);
}

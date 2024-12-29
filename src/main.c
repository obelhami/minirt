/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 02:27:21 by obelhami          #+#    #+#             */
/*   Updated: 2024/12/29 21:22:15 by ajawad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_error(char *str)
{
	printf("%s", str);
	garbage_collector();
}

int	main(int argc, char **argv)
{
	t_world_setup	world_setup;
	t_windata		windata;

	world_setup.ambient = NULL;
	world_setup.camera = NULL;
	world_setup.light = NULL;
	world_setup.world = NULL;
	if (argc < 2)
		ft_error("Error: the number of arguments is invalid\n");
	if (argc == 2)
	{
		if (!ft_strstr(argv[1], ".rt"))
			ft_error("Error: the argument must be finish with .rt\n");
	}
	parsing(&world_setup, argv[1]);
	create_window(&windata);
	setup_3d_world(&windata, &world_setup);
	render(&windata, &world_setup);
	mlx_loop(windata.mlx);
	return (0);
}

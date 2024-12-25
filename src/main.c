/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 02:27:21 by obelhami          #+#    #+#             */
/*   Updated: 2024/12/25 06:39:45 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int check_line(char *str)
{
	char	**split;
	if (str[0] == '\n')
		return (0);
	split = ft_ft_split(str);
	if (!ft_strcmp(split[0], "A"))
		return (AMBIENT);
	else if (!ft_strcmp(split[0], "C"))
		return (CAMERA);
	else if (!ft_strcmp(split[0], "L"))
		return (LIGHT);
	else if (!ft_strcmp(split[0], "sp"))
		return (SPHERE);
	else if (!ft_strcmp(split[0], "pl"))
		return (PLANE);
	else if (!ft_strcmp(split[0], "cy"))
		return (CYLINDER);
	else
		return(1);
	return (0);
}

int	parsing(t_world_setup *world_setup, char *config_file_name)
{
	int		fd;
	int		type_of_object;
	char	**split;
	char	*line;

	fd = open(config_file_name, O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		if (line[0] != '\n' && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		split = ft_ft_split(line);
		type_of_object = check_line(line);
		if (type_of_object == CAMERA)
		{
			if (world_setup->camera != NULL)
			{
				printf("ERROR2\n");
				return (1);
			}
			world_setup->camera = create_camera(split);
		}
		else if (type_of_object == AMBIENT)
		{
			if (world_setup->ambient != NULL)
			{
				printf("ERROR1\n");
				return (1);
			}
			world_setup->ambient = create_ambient(split);
		}
		else if (type_of_object == LIGHT)
		{
			if (world_setup->light != NULL)
			{
				printf("ERROR3\n");
				return (1);
			}
			world_setup->light = create_light(split);
		} 
		else if (type_of_object == SPHERE)
			add_object(&world_setup->world, create_object(SPHERE, create_sphere(split)));
		else if (type_of_object == PLANE)
			add_object(&world_setup->world, create_object(PLANE, create_plane(split)));
		else if (type_of_object == CYLINDER)
			add_object(&world_setup->world, create_object(CYLINDER, create_cylinder(split)));
		else if (type_of_object == 1)
		{
			printf("ERROR6\n");
			exit(1);
		}
		free(line);
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_world_setup	world_setup;
	// t_windata		windata;

	world_setup.ambient = NULL;
	world_setup.camera = NULL;
	world_setup.light = NULL;
	world_setup.world = NULL;
	if (argc < 2)
	{
		printf("the number of arguments is invalid\n");
		exit(1);
	}
	if (argc == 2)
	{
		if (!ft_strstr(argv[1], ".rt"))
		{
			printf("Error: the argument must be finish with .rt\n");
			exit(1);
		}
	}
	if (parsing(&world_setup, argv[1]))
		return (1);
	// if (create_window(&windata))
	// 	return (1);
	// setup_3d_world(&windata, &world_setup);
	// render(&windata, &world_setup);
	// mlx_loop(windata.mlx);
	return (0);
}

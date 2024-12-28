/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 05:21:49 by obelhami          #+#    #+#             */
/*   Updated: 2024/12/28 05:48:57 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_line(char *str)
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
		return (1);
	return (0);
}

static void	if_type_is_camera(t_world_setup *world_setup, char **split)
{
	if (world_setup->camera != NULL)
		ft_error("must be only one camera\n");
	world_setup->camera = create_camera(split);
}

static void	if_type_is_light(t_world_setup *world_setup, char **split)
{
	if (world_setup->light != NULL)
		ft_error("must be only one light\n");
	world_setup->light = create_light(split);
}

static void	ft_parsing(t_world_setup *world_setup, char **split)
{
	int	type_of_object;

	type_of_object = check_line(split[0]);
	if (type_of_object == CAMERA)
		if_type_is_camera(world_setup, split);
	else if (type_of_object == AMBIENT)
	{
		if (world_setup->ambient != NULL)
			ft_error("must be only one ambient\n");
		world_setup->ambient = create_ambient(split);
	}
	else if (type_of_object == LIGHT)
		if_type_is_light(world_setup, split);
	else if (type_of_object == SPHERE)
		add_object(&world_setup->world,
			create_object(SPHERE, create_sphere(split)));
	else if (type_of_object == PLANE)
		add_object(&world_setup->world,
			create_object(PLANE, create_plane(split)));
	else if (type_of_object == CYLINDER)
		add_object(&world_setup->world, create_object(CYLINDER,
				create_cylinder(split)));
	else if (type_of_object == 1)
		ft_error("Error: the object is invalid\n");
}

int	parsing(t_world_setup *world_setup, char *config_file_name)
{
	int		fd;
	char	**split;
	char	*line;

	fd = open(config_file_name, O_RDONLY);
	if (fd < 0)
	{
		printf("Error: the file %s is invalid\n", config_file_name);
		exit(1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] != '\n' && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		split = ft_ft_split(line);
		if (split[0] != NULL)
			ft_parsing(world_setup, split);
	}
	return (0);
}

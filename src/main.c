#include "minirt.h"

t_cylinder  *create_cylinder(char **split)
{
	char	**coordinate;
	int i;
	double  diameter;
	double  height;
	char	**orientation_vector;
	char	**rgb;
	t_cylinder  *cylinder;
	
	cylinder = malloc(sizeof(t_cylinder));
	if (ft_dblptrlen(split) != 6)
	{
		printf("Error: the cylinder is invalid\n");
		exit(1);
	}
	coordinate = ft_split(split[1], ',');
	i = 0;
	while (coordinate[i])
	{
		if (ft_isfloat(coordinate[i]))
		{
			printf("Error: the coordinates is invalid1\n");
			exit(1);
		}
		i++;
	}
	if (i != 3)
	{
		printf("Error: the coordinates is invalid2\n");
		exit(1);
	}
	fill_coordinate(&cylinder->center, coordinate);
	orientation_vector = ft_split(split[2], ',');
	i = 0;
	while (orientation_vector[i])
	{
		if (ft_isfloat(orientation_vector[i]) ||
			(ft_atof(orientation_vector[i]) < -1.00 || ft_atof(orientation_vector[i]) > 1.00))
		{
			printf("Error: the coordinates is invalid1\n");
			exit(1);
		}
		i++;
	}
	if (i != 3)
	{
		printf("Error: the coordinates is invalid3\n");
		exit(1);
	}
	fill_coordinate(&cylinder->axis_vec, orientation_vector);
	diameter = ft_atof(split[3]);
	if (ft_isfloat(split[3]) || diameter < 0.0)
	{
		printf("the range of diameter is invalid1\n");
		exit(1);
	}
	cylinder->diameter = diameter;
	height = ft_atof(split[4]);
	if (ft_isfloat(split[4]) || height < 0.0)
	{
		printf("the range of height is invalid\n");
		exit(1);
	}
	cylinder->height = height;
	rgb = ft_split(split[5], ',');
	i = 0;
	while (rgb[i])
	{
		if (ft_ft_isdigit(rgb[i]) == 1)
		{
			printf("Error: the color of cylinder is invalid\n");
			exit(1);
		}
		if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
		{
			printf("Error: the color of cylinder is invalid\n");
			exit(1);
		}
		i++;
	}
	if (i != 3)
	{
		printf("Error: the coordinates is invalid4\n");
		exit(1);
	}
	fill_rgb(&cylinder->color, rgb);
	ft_free(split);
	return (cylinder);
}

t_plane *create_plane(char **split)
{
	char	**coordinate;
	int i;
	char	**orientation_vector;
	char	**rgb;
	t_plane *plane;

	plane = malloc(sizeof(t_plane));
	if (ft_dblptrlen(split) != 4)
	{
		printf("Error: the argumment of plane is invalid\n");
		exit(1);
	}
	coordinate = ft_split(split[1], ',');
	i = 0;
	while (coordinate[i])
	{
		if (ft_isfloat(coordinate[i]))
		{
			printf("Error: the coordinates is invalid5\n");
			exit(1);
		}
		i++;
	}
	if (i != 3)
	{
		printf("Error: the coordinates is invalid6\n");
		exit(1);
	}
	fill_coordinate(&plane->point_cord, coordinate);
	orientation_vector = ft_split(split[2], ',');
	i = 0;
	while (orientation_vector[i])
	{
		if (ft_isfloat(orientation_vector[i]) ||
			(ft_atof(orientation_vector[i]) < -1.00 || ft_atof(orientation_vector[i]) > 1.00))
		{
			printf("Error: the coordinates is invalid7\n");
			exit(1);
		}
		i++;
	}
	if (i != 3)
	{
		printf("Error: the coordinates is invalid8\n");
		exit(1);
	}
	fill_coordinate(&plane->normal_vec, orientation_vector);
	rgb = ft_split(split[3], ',');
	i = 0;
	while (rgb[i])
	{
		if (ft_ft_isdigit(rgb[i]) == 1)
		{
			printf("Error: the color of plane is invalid\n");
			exit(1);
		}
		if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
		{
			printf("Error: the color of plane is invalid\n");
			exit(1);
		}
		i++;
	}
	if (i != 3)
	{
		printf("Error: the coordinates is invalid9\n");
		exit(1);
	}
	fill_rgb(&plane->color, rgb);
	ft_free(split);
	return (plane);
}

t_light *create_light(char **split)
{
	int i;
	double  brightness;
	char	**coordinate;
	char	**rgb;
	t_light *light;

	light = malloc(sizeof(t_light));
	if (ft_dblptrlen(split) != 4)
	{
		printf("Error: the argumment of light is invalid\n");
		exit(1);
	}
	i = 0;
	coordinate = ft_split(split[1], ',');
	while (coordinate[i])
	{
		if (ft_isfloat(coordinate[i]))
		{
			printf("Error: the coordinates of light is invalid13\n");
			exit(1);
		}
		i++;
	}
	if (i != 3)
	{
		printf("Error: the coordinates is invalid14\n");
		exit(1);
	}
	fill_coordinate(&light->cord, coordinate);
	brightness = ft_atof(split[2]);
	if (ft_isfloat(split[2]) || (brightness < 0.0 || brightness > 1.0))
	{
		printf("the range of brightness is invalid\n");
		exit(1);
	}
	light->brightness = brightness;
	rgb = ft_split(split[3], ',');
	i = 0;
	while (rgb[i])
	{
		if (ft_ft_isdigit(rgb[i]) == 1)
		{
			printf("Error: the color of light is invalid\n");
			exit(1);
		}
		if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
		{
			printf("Error: the color of light is invalid\n");
			exit(1);		}
		i++;
	}
	if (i != 3)
	{
		printf("Error: the coordinates is invalid15\n");
		exit(1);
	}
	fill_rgb(&light->color, rgb);
	ft_free(split);
	return (light);
}

t_camera	*create_camera(char **split)
{
	char	**coordinate;
	int i;
	char	**orientation_vector;
	int fov;
	t_camera	*camera;

	camera = malloc(sizeof(t_camera));
	if (ft_dblptrlen(split) != 4)
	{
		printf("Error: the argumment of camera is invalid\n");
		exit(1);
	}
	coordinate = ft_split(split[1], ',');
	i = 0;
	while (coordinate[i])
	{
		if (ft_isfloat(coordinate[i]))
		{
			printf("Error: the coordinates is invalid16\n");
			exit(1);
		}
		i++;
	}
	if (i != 3)
	{
		printf("Error: the coordinates is invalid17\n");
		exit(1);
	}
	fill_coordinate(&camera->cord, coordinate);
	orientation_vector = ft_split(split[2], ',');
	i = 0;
	while (orientation_vector[i])
	{
		if (ft_isfloat(orientation_vector[i]) ||
			(ft_atof(orientation_vector[i]) < -1.00 || ft_atof(orientation_vector[i]) > 1.00))
		{
			printf("Error: the coordinates is invalid18\n");
			exit(1);
		}
		i++;
	}
	if (i != 3)
	{
		printf("Error: the coordinates is invalid19\n");
		exit(1);
	}
	fill_coordinate(&camera->orientation_vec, orientation_vector);
	fov = ft_atof(split[3]);
	if (ft_ft_isdigit(split[3]) || (fov < 0 || fov > 180))
	{
		printf("the range of field of view is invalid\n");
		exit(1);
	}
	camera->hfov = fov;
	ft_free(split);
	return (camera);
}

t_ambient   *create_ambient(char **split)
{
	char	**rgb;
	double  light_ratio;
	int i;
	t_ambient   *ambient;

	ambient = malloc(sizeof(t_ambient));
	if (ft_dblptrlen(split) != 3)
	{
		printf("Error: the argumment of camera is invalid\n");
		exit(1);
	}
	i = 0;
	light_ratio = ft_atof(split[1]);
	if (light_ratio < 0.0 || light_ratio > 1.0)
	{
		printf("Error: the light ratio is invalid\n");
		exit(1);
	}
	ambient->lighting_ratio = light_ratio;
	rgb = ft_split(split[2], ',');
	while (rgb[i])
	{
		if (ft_ft_isdigit(rgb[i]) == 1)
		{
			printf("Error: the color of ambient is invalid\n");
			exit(1);
		}
		if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
		{
			printf("Error: the color of ambient is invalid\n");
			exit(1);
		}
		i++;
	}
	if (i != 3)
	{
		printf("Error: the coordinates is invalid20\n");
		exit(1);
	}
	fill_rgb(&ambient->color, rgb);
	ft_free(split);
	return (ambient);
}

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

// void	print_args(t_object_container *world)
// {
// 	t_sphere	*sphere;
// 	t_plane		*plane;
// 	t_cylinder	*cylinder;

// 	while (world)
// 	{
// 		if (world->type == SPHERE)
// 		{
// 			sphere = (t_sphere *)world->object;
// 			printf("SPHERE:\n");
// 			printf("\tcord: x=%f, y=%f, z=%f\n", sphere->cord.x,
// 					sphere->cord.y, sphere->cord.z);
// 			printf("\tdiameter: %f\n", sphere->diameter);
// 			printf("\trgb: r=%d, g=%d, b=%d\n", sphere->rgb.red,
// 					sphere->rgb.green, sphere->rgb.blue);
// 		}
// 		else if (world->type == PLANE)
// 		{
// 			plane = (t_plane *)world->object;
// 			printf("PLANE:\n");
// 			printf("\tcord: x=%f, y=%f, z=%f\n", plane->cord.x, plane->cord.y,
// 					plane->cord.z);
// 			printf("\tvector: x=%f, y=%f, z=%f\n", plane->vectors.x,
// 					plane->vectors.y, plane->vectors.z);
// 			printf("\trgb: r=%d, y=%d, z=%d\n", plane->rgb.red,
// 					plane->rgb.green, plane->rgb.blue);
// 		}
// 		else if (world->type == CYLINDER)
// 		{
// 			cylinder = (t_cylinder *)world->object;
// 			printf("CYLINDER:\n");
// 			printf("\tcord: x=%f, y=%f, z=%f\n", cylinder->cord.x,
// 					cylinder->cord.y, cylinder->cord.z);
// 			printf("\tvector: x=%f, y=%f, z=%f\n", cylinder->vectors.x,
// 					cylinder->vectors.y, cylinder->vectors.z);
// 			printf("\tdiameter: %f\n", cylinder->cy_diameter);
// 			printf("\theight: %f\n", cylinder->cy_height);
// 			printf("\trgb: r=%d, g=%d, b=%d\n", cylinder->rgb.red,
// 					cylinder->rgb.green, cylinder->rgb.blue);
// 		}
// 		world = world->next;
// 		printf("__________________________________________________________\n");
// 	}
// 	printf("DONE\n");
// }

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
	t_windata		windata;

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
	if (create_window(&windata))
		return (1);
	create_image(&windata);
	setup_3d_world(&windata, &world_setup);
	render(&windata, &world_setup);
	mlx_loop(windata.mlx);
	return (0);
}

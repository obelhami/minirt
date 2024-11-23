#include "minirt.h"

void    fill_coordinate(t_vec3 *object, char **coordinate)
{
    object->x = ft_atof(coordinate[0]);
    object->y = ft_atof(coordinate[1]);
    object->z = ft_atof(coordinate[2]);
}

void    fill_rgb(t_rgb *object, char **rgb)
{
    object->red = ft_atoi(rgb[0]);
    object->green = ft_atoi(rgb[1]);
    object->blue = ft_atoi(rgb[2]);
}

t_cylinder  *create_cylinder(char **split)
{
    char    **coordinate;
    int i;
    double  diameter;
    double  height;
    char    **orientation_vector;
    char    **rgb;
    t_cylinder  *cylinder;
    
    cylinder = malloc(sizeof(t_cylinder));
    if (split[1] == NULL)
    {
        printf("no parameter in cylinder \n");
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
    fill_coordinate(&cylinder->cord, coordinate);
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
    fill_coordinate(&cylinder->vectors, orientation_vector);
    diameter = ft_atof(split[3]);
    if (ft_isfloat(split[3]) || diameter < 0.0)
    {
        printf("the range of diameter is invalid1\n");
        exit(1);
    }
    cylinder->cy_diameter = diameter;
    height = ft_atof(split[4]);
    if (ft_isfloat(split[4]) || height < 0.0)
    {
        printf("the range of height is invalid\n");
        exit(1);
    }
    cylinder->cy_height = height;
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
    fill_rgb(&cylinder->rgb, rgb);
    if (split[6])
    {
        printf("Error: the cylinder is invalid\n");
        exit(1);
    }
    ft_free(split);
    return (cylinder);
}

t_plane *create_plane(char **split)
{
    char    **coordinate;
    int i;
    char    **orientation_vector;
    char    **rgb;
    t_plane *plane;

    plane = malloc(sizeof(t_plane));
    if (split[1] == NULL)
    {
        printf("no parameter in plane \n");
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
    fill_coordinate(&plane->cord, coordinate);
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
    fill_coordinate(&plane->vectors, orientation_vector);
    rgb = ft_split(split[3], ',');
    i = 0;
    while (rgb[i])
    {
        printf("rgb==>%s\n", rgb[i]);
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
    fill_rgb(&plane->rgb, rgb);
    if (split[4])
    {
        printf("Error: the plane is invalid\n");
        exit(1);
    }
    ft_free(split);
    return (plane);
}

t_sphere    *create_sphere(char **split)
{
    char    **coordinate;
    int i;
    double  diameter;
    char    **rgb;
    t_sphere    *sphere;

    sphere = malloc(sizeof(t_sphere));
    if (split[1] == NULL)
    {
        printf("no parameter in sphere \n");
        exit(1);
    }
    coordinate = ft_split(split[1], ',');
    i = 0;
    while (coordinate[i])
    {
        if (ft_isfloat(coordinate[i]))
        {
            printf("Error: the coordinates is invalid10\n");
            exit(1);
        }
        i++;
    }
    if (i != 3)
    {
        printf("Error: the coordinates is invalid11\n");
        exit(1);
    }
    fill_coordinate(&sphere->cord, coordinate);
    diameter = ft_atof(split[2]);
    if (ft_isfloat(split[2]) || diameter < 0.0)
    {
        printf("the range of diameter is invalid\n");
        exit(1);
    }
    sphere->diameter = diameter;
    rgb = ft_split(split[3], ',');
    i = 0;
    while (rgb[i])
    {
        if (ft_ft_isdigit(rgb[i]) == 1)
        {
            printf("Error: the color of sphere is invalid\n");
            exit(1);
        }
        if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
        {
            printf("Error: the color of sphere is invalid\n");
            exit(1);
        }
        i++;
    }
    if (i != 3)
    {
        printf("Error: the coordinates is invalid12\n");
        exit(1);
    }
    fill_rgb(&sphere->rgb, rgb);
    if (split[4])
    {
        printf("Error: the sphere is invalid\n");
        exit(1);
    }
    ft_free(split);
    return (sphere);
}

t_light *create_light(char **split)
{
    int i;
    double  brightness;
    char    **coordinate;
    char    **rgb;
    t_light *light;

    light = malloc(sizeof(t_light));
    i = 0;
    if (split[1] == NULL)
    {
        printf("no parameter in lighting \n");
        exit(1);
    }
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
            exit(1);        }
        i++;
    }
    if (i != 3)
    {
        printf("Error: the coordinates is invalid15\n");
        exit(1);
    }
    fill_rgb(&light->rgb, rgb);
    if (split[4])
    {
        printf("Error: the light is invalid\n");
        exit(1);
    }
    ft_free(split);
    return (light);
}

t_camera    *create_camera(char **split)
{
    char    **coordinate;
    int i;
    char    **orientation_vector;
    int fov;
    t_camera    *camera;

    camera = malloc(sizeof(t_camera));
    if (split[1] == NULL)
    {
        printf("no parameter in camera \n");
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
    fill_coordinate(&camera->vectors, orientation_vector);
    fov = ft_atof(split[3]);
    if (ft_ft_isdigit(split[3]) || (fov < 0 || fov > 180))
    {
        printf("the range of field of view is invalid\n");
        exit(1);
    }
    camera->fov = fov;
    if (split[4])
    {
        printf("Error: the camera is invalid\n");
        exit(1);
    }
    ft_free(split);
    return (camera);
}

t_ambient   *create_ambient(char **split)
{
    char    **rgb;
    double  light_ratio;
    int i;
    t_ambient   *ambient;

    ambient = malloc(sizeof(t_ambient));
    if (split[1] == NULL)
    {
        printf("no parameter in ambient light \n");
        exit(1);
    }
    i = 0;
    light_ratio = ft_atof(split[1]);
    if (light_ratio < 0.0 || light_ratio > 1.0)
    {
        printf("Error: the light ratio is invalid\n");
        exit(1);
    }
    ambient->ratio = light_ratio;
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
    fill_rgb(&ambient->rgb, rgb);
    if (split[3])
    {
        printf("Error: the ambient light is invalid\n");
        exit(1);
    }
    ft_free(split);
    return (ambient);
}

int check_line(char *str)
{
    char    **split;
    if (str[0] == '\n')
        return (0);
    split = ft_split(str, ' ');
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

int main(int argc, char **argv)
{
    int fd;
    char *line;
    t_ambient *ambient = NULL;
    t_camera *camera = NULL;
    t_light *light = NULL;
    t_object_container *world = NULL;
    int    type_of_object;
    char    **split;

    line = NULL;
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
    fd = open(argv[1], O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        if (line[0] != '\n' && line[ft_strlen(line) - 1] == '\n')
            line[ft_strlen(line) - 1] = '\0';
        split = ft_split(line, ' ');
        type_of_object = check_line(line);
        if (type_of_object == CAMERA)
        {
            if (camera != NULL)
            {
                printf("ERROR1\n");
                return (1);
            }
            camera = create_camera(split);
        }
        else if (type_of_object == AMBIENT)
        {
            if (ambient != NULL)
            {
                printf("ERROR\n");
                return (1);
            }
            ambient = create_ambient(split);
        }
        else if (type_of_object == LIGHT)
        {
            if (light != NULL)
            {
                printf("ERROR\n");
                return (1);
            }
            light = create_light(split);
        } 
        else if (type_of_object == SPHERE)
            add_object(&world, create_object(SPHERE, create_sphere(split)));
        else if (type_of_object == PLANE)
            add_object(&world, create_object(PLANE, create_plane(split)));
        else if (type_of_object == CYLINDER)
            add_object(&world, create_object(CYLINDER, create_cylinder(split)));
        else if (type_of_object == 1)
        {
            printf("ERROR1\n");
            exit(1);
        }
        free(line);
    }
    return (0);
}

#include "../minirt.h"

void    cylinder(char **split)
{
    char    **coordinate;
    int i;
    double  diameter;
    double  height;
    char    **orientation_vector;
    char    **rgb;

    if (split[1] == NULL)
    {
        printf("no parameter in cylinder \n");
        exit(1);
    }
    coordinate = ft_split(split[1], ',');
    i = 0;
    while (coordinate[i])
    {
        if (ft_isfloat(coordinate[i]) || coordinate[3])
        {
            printf("Error: the coordinates is invalid\n");
            exit(1);
        }
        i++;
    }
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
    diameter = ft_atof(split[3]);
    if (ft_isfloat(split[3]) || diameter < 0.0)
    {
        printf("the range of diameter is invalid1\n");
        exit(1);
    }
    height = ft_atof(split[4]);
    if (ft_isfloat(split[4]) || height < 0.0)
    {
        printf("the range of height is invalid\n");
        exit(1);
    }
    rgb = ft_split(split[5], ',');
    i = 0;
    while (rgb[i])
    {
        if (ft_ft_isdigit(rgb[i]) == 1)
        {
            printf("Error: the color is invalid1\n");
            exit(1);
        }
        if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
        {
            printf("Error: the color is invalid\n");
            exit(1);
        }
        i++;
    }
    if (split[6])
    {
        printf("Error: the cylinder is invalid\n");
        exit(1);
    }
    ft_free(split);
}

void    plane(char **split)
{
    char    **coordinate;
    int i;
    char    **orientation_vector;
    char    **rgb;

    if (split[1] == NULL)
    {
        printf("no parameter in plane \n");
        exit(1);
    }
    coordinate = ft_split(split[1], ',');
    i = 0;
    while (coordinate[i])
    {
        if (ft_isfloat(coordinate[i]) || coordinate[3])
        {
            printf("Error: the coordinates is invalid\n");
            exit(1);
        }
        i++;
    }
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
    rgb = ft_split(split[3], ',');
    i = 0;
    while (rgb[i])
    {
        if (ft_ft_isdigit(rgb[i]) == 1)
        {
            printf("Error: the color is invalid1\n");
            exit(1);
        }
        if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
        {
            printf("Error: the color is invalid\n");
            exit(1);
        }
        i++;
    }
    if (split[4])
    {
        printf("Error: the plane is invalid\n");
        exit(1);
    }
    ft_free(split);
}

void    sphere(char **split)
{
    char    **coordinate;
    int i;
    double  diameter;
    char    **rgb;

    if (split[1] == NULL)
    {
        printf("no parameter in sphere \n");
        exit(1);
    }
    coordinate = ft_split(split[1], ',');
    i = 0;
    while (coordinate[i])
    {
        if (ft_isfloat(coordinate[i]) || coordinate[3])
        {
            printf("Error: the coordinates is invalid\n");
            exit(1);
        }
        i++;
    }
    diameter = ft_atof(split[2]);
    if (ft_isfloat(split[2]) || diameter < 0.0)
    {
        printf("the range of diameter is invalid\n");
        exit(1);
    }
    rgb = ft_split(split[3], ',');
    i = 0;
    while (rgb[i])
    {
        if (ft_ft_isdigit(rgb[i]) == 1)
        {
            printf("Error: the color is invalid1\n");
            exit(1);
        }
        if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
        {
            printf("Error: the color is invalid\n");
            exit(1);
        }
        i++;
    }
    if (split[4])
    {
        printf("Error: the sphere is invalid\n");
        exit(1);
    }
    ft_free(split);
}

void    light(char **split)
{
    int i;
    double  brightness;
    char    **coordinate;
    char    **rgb;

    i = 0;
    if (split[1] == NULL)
    {
        printf("no parameter in lighting \n");
        exit(1);
    }
    coordinate = ft_split(split[1], ',');
    while (coordinate[i])
    {
        if (ft_isfloat(coordinate[i]) || coordinate[3])
        {
            printf("Error: the coordinates of light is invalid\n");
            exit(1);
        }
        i++;        
    }
    brightness = ft_atof(split[2]);
    if (ft_isfloat(split[2]) || (brightness < 0.0 || brightness > 1.0))
    {
        printf("the range of brightness is invalid\n");
        exit(1);
    }
    rgb = ft_split(split[3], ',');
    i = 0;
    while (rgb[i])
    {
        if (ft_ft_isdigit(rgb[i]) == 1)
        {
            printf("Error: the color is invalid1\n");
            exit(1);
        }
        if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
        {
            printf("Error: the color is invalid\n");
            exit(1);
        }
        i++;
    }
    if (split[4])
    {
        printf("Error: the camera is invalid\n");
        exit(1);
    }
    ft_free(split);
}

void    camera(char **split)
{
    char    **coordinate;
    int i;
    char    **orientation_vector;
    int fov;

    if (split[1] == NULL)
    {
        printf("no parameter in camera \n");
        exit(1);
    }
    coordinate = ft_split(split[1], ',');
    i = 0;
    while (coordinate[i])
    {    
        if (ft_isfloat(coordinate[i]) || coordinate[3])
        {
            printf("Error: the coordinates is invalid\n");
            exit(1);
        }
        i++;
    }
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
    fov = ft_atof(split[3]);
    if (ft_ft_isdigit(split[3]) || (fov < 0 || fov > 180))
    {
        printf("the range of field of view is invalid\n");
        exit(1);
    }
    if (split[4])
    {
        printf("Error: the camera is invalid\n");
        exit(1);
    }
    ft_free(split);
}

void ambient(char **split)
{
    char    **rgb;
    double  light_ratio;
    int i;

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
    rgb = ft_split(split[2], ',');
    while (rgb[i])
    {
        if (ft_ft_isdigit(rgb[i]) == 1)
        {
            printf("Error: the color is invalid1\n");
            exit(1);
        }
        if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
        {
            printf("Error: the color is invalid\n");
            exit(1);
        }
        i++;
    }
    if (split[3])
    {
        printf("Error: the ambient light is invalid\n");
        exit(1);
    }
    ft_free(split);
}

int check_line(char *str)
{
    char    **split;

    if (str[0] == '\n')
        return (0);
    str[ft_strlen(str) - 1] = '\0';
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
        split = ft_split(line, ' ');
        type_of_object = check_line(line);
        if (type_of_object == CAMERA)
        {
            if (camera != NULL)
            {
                printf("ERROR\n");
                return (1);
            }
            camera = create_camera(line);
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
            add_object(world, create_object(SPHERE, create_sphere(split)));
        else if (type_of_object == PLANE)
            add_object(world, create_object(PLANE, create_plane(split)));
        else if (type_of_object == CYLINDER)
            add_object(world, create_object(CYLINDER, create_cylinder(split)));
        free(line);
    }
    return (0);
}

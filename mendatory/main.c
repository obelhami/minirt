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
}

int check_line(char *str)
{
    char    **split;

    split = ft_split(str, ' ');
    if (!ft_strcmp(split[0], "A"))
        ambient(split);
    else if (!ft_strcmp(split[0], "C"))
        camera(split);
    else if (!ft_strcmp(split[0], "L"))
        light(split);
    else if (!ft_strcmp(split[0], "sp"))
        sphere(split);
    else if (!ft_strcmp(split[0], "pl"))
        plane(split);
    else if (!ft_strcmp(split[0], "cy"))
        cylinder(split);
    else
        return(1);
    return (0);
}

int main(int argc, char **argv)
{
    int fd;
    char *line;

    line = NULL;
    if (argc < 2)
    {
        printf("the number of arguments is invalid\n");
        exit(1);
    }
    printf("here\n");
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
        if (check_line(line))
        {
            printf("Error: the line is invalid\n");
            exit(1);
        }
    }
    return (0);
}

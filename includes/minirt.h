#ifndef MINIRT_H
#define MINIRT_H

#include "../src/libft/libft.h"
#include "../src/get_next_line/get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CAMERA 2
#define AMBIENT 3
#define LIGHT 4
#define SPHERE 5
#define PLANE 6
#define CYLINDER 7


typedef struct s_rgb
{
	int	red;
	int green;
	int	blue;
}				t_rgb;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}				t_vec3;

typedef struct s_light
{
	t_vec3	cord;
	double	brightness;
	t_rgb	rgb;
}				t_light;

typedef struct s_object_container
{
	int							type;
	void						*object;
	struct s_object_container	*next;
}				t_object_container;

typedef	struct s_camera
{
	t_vec3	cord;
	t_vec3	vectors;
	int	fov;
}			t_camera;

typedef struct s_ambient
{
	double	ratio;
	t_rgb	rgb;
}			t_ambient;

typedef struct s_sphere
{
	t_vec3	cord;
	double	diameter;
	t_rgb	rgb;
}	t_sphere;

typedef struct s_plane
{
	t_vec3	cord;
	t_vec3	vectors;
 	t_rgb	rgb;
}			t_plane;

typedef struct s_cylinder
{
	t_vec3	cord;
	t_vec3	vectors;
	double	cy_diameter;
	double	cy_height;
	t_rgb	rgb;
}			t_cylinder;

int		ft_strstr(char *str, char *to_find);
int		check_line(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_ft_isdigit(char *str);
float	ft_atof(char *str);
int		ft_isfloat(char *str);
char	**ft_free(char **ptr);
t_object_container	*create_object(int type, void *object);
void	add_object(t_object_container **world, t_object_container *new_object);

#endif

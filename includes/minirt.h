/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 05:36:48 by obelhami          #+#    #+#             */
/*   Updated: 2024/12/28 05:36:49 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../src/libft/libft.h"
# include "../src/get_next_line/get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../src/mlx_clone/mlx.h"
# include <math.h>

# define CAMERA 2
# define AMBIENT 3
# define LIGHT 4
# define SPHERE 5
# define PLANE 6
# define CYLINDER 7

# define ESC 65307

# define PI 3.14159265358979323
# define EPSILON 1e-4

# define H_REC	(t_hit_record)
# define T_POINT3 t_vec3

# define BOOL int
# define TRUE 1
# define FALSE 0

# define UPPER_BASE 0
# define LOWER_BASE 1

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}				t_vec3;

typedef struct s_rgb
{
	int	r;
	int g;
	int	b;
}				t_rgb;

typedef struct s_discriminant {
	double	a;
	double	b;
	double	c;
	double	delta;
}				t_discriminant;

typedef struct s_hit_record {
	void		*object;
	T_POINT3	*point;
	t_vec3		*normal;
	double		t;
	t_rgb		*color;
}				t_hit_record;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_light
{
	t_vec3	cord;
	double	brightness;
	t_rgb	color;
}				t_light;


typedef	struct s_camera
{
	t_vec3	cord;
	t_vec3	orientation_vec;
	int		hfov;
}				t_camera;

typedef struct s_ambient
{
	double	lighting_ratio;
	t_rgb	color;
}				t_ambient;

typedef struct s_sphere
{
	t_vec3	center;
	double	diameter;
	double	radius;
	t_rgb	color;
}				t_sphere;

typedef struct s_plane
{
	t_vec3	point_cord;
	t_vec3	normal_vec;
 	t_rgb	color;
}				t_plane;

typedef struct s_cylinder
{
	t_vec3		center;
	t_vec3		axis_vec;
	double		diameter;
	double		height;
	t_rgb		color;
	double		radius;
	T_POINT3	*upper_base;
	T_POINT3	*lower_base;
}				t_cylinder;

typedef struct s_windata {
	void	*mlx;
	void	*mlx_win;
	int		height;
	int		width;
	double	aspect_ratio;
	t_img	img;
}				t_windata;

typedef struct s_ray {
	T_POINT3	*orig;
	T_POINT3	*dir;
}				t_ray;

typedef struct s_interval {
	double	min;
	double	max;
}				t_interval;

typedef struct s_object_container
{
	int							type;
	void						*object;
	BOOL						(*hit)(void *, t_interval, t_hit_record *,
								t_ray *);
	struct s_object_container	*next;
}				t_object_container;

typedef struct s_wolrd_setup {
	t_ambient			*ambient;
	t_camera			*camera;
	t_light				*light;
	t_object_container	*world;
	double				viewport_width;
	double				viewport_height;
	t_vec3				*viewport_u;
	t_vec3				*viewport_v;
	t_vec3				*delta_u;
	t_vec3				*delta_v;
	T_POINT3			*pixel00_loc;
	T_POINT3			v_camera;
	int					samples_per_pixel;
}				t_world_setup;

int					ft_strstr(char *str, char *to_find);
int					check_line(char *str);
int					ft_strcmp(char *s1, char *s2);
int					ft_ft_isdigit(char *str);
float				ft_atof(char *str);
int					ft_isfloat(char *str);
char				**ft_free(char **ptr);
t_object_container	*create_object(int type, void *object);
void				add_object(t_object_container **world,
					t_object_container *new_object);
char				**ft_ft_split(char const *s);
int					create_window(t_windata *window_data);
int					create_image(t_windata *win_data);
double				degrees_to_radians(double degrees);
int					setup_3d_world(t_windata *win, t_world_setup *world_setup);
int					render(t_windata *win, t_world_setup *world_setup);
t_vec3				*scalar_op(double t, t_vec3 *vec);
t_vec3				*division_op(t_vec3 *v, double t);
t_vec3				*addition_op(t_vec3 *v, t_vec3 *u);
t_vec3				*subtraction_op(t_vec3 *v, t_vec3 *u);
t_vec3				*hadamard_product(t_vec3 *v, t_vec3 *u);
double				dot_product(t_vec3 *v, t_vec3 *u);
t_vec3				*cross_product(t_vec3 *v, t_vec3 *u);
double				vector_length_squared(t_vec3 *vec);
double				vector_length(t_vec3 *vec);
t_vec3				*unit_vector(t_vec3 *vector);
T_POINT3			*ray_at(t_ray *ray, double t);
void				fill_vec3(t_vec3 *vec, double x, double y, double z);
t_vec3				*create_vec3(double x, double y, double z);
t_sphere			*create_sphere(char **split);
BOOL				hit_any_object(t_object_container *world,
					t_interval interval, t_hit_record *rec, t_ray *ray);
BOOL				hit_sphere(void *ptr, t_interval interval,
					t_hit_record *rec, t_ray *ray);
int					ft_dblptrlen(char **str);
void				fill_rgb(t_rgb *object, char **rgb);
void				fill_coordinate(t_vec3 *object, char **coordinate);
double				random_double(void);
double				interval_random_double(t_interval interval);
BOOL				hit_plane(void *ptr, t_interval interval,
					t_hit_record *rec, t_ray *ray);
BOOL				hit_cylinder(void *ptr, t_interval interval,
					t_hit_record *rec, t_ray *ray);
void				set_normal_against_ray(t_ray *ray, t_hit_record *rec);
BOOL				closeto_zero(double value);
void				get_bases_centers(t_cylinder *cylinder);
t_vec3				*reflect_vec(t_vec3 *incident_vec, t_vec3 *surface_normal);
t_rgb				*colors_addition(t_rgb *color1, t_rgb *color2);
t_rgb				*color_multiplication(t_rgb *color1, t_rgb *color2);
t_rgb				*scale_color(double scalar, t_rgb *color);
double				max(double min, double value);
int					clamp(double min, double max, int var);
double				calculate_light_effect(t_world_setup *world_setup,
					t_hit_record *rec);
BOOL				hit_light(t_object_container *world, t_ray *ray, t_light *light);
t_rgb				*ray_color(t_world_setup *world_setup, t_ray *ray);
t_ray				*get_ray(int jdx, int idx, t_world_setup *world_setup);
t_cylinder  *create_cylinder(char **split);
void	utils(char  *str);
void	ft_check_isfloat(char **str, char *error);
void	ft_check_rgb(char **rgb, char *error);
t_plane *create_plane(char **split);
t_light *create_light(char **split);
t_camera	*create_camera(char **split);
t_ambient   *create_ambient(char **split);
int	parsing(t_world_setup *world_setup, char *config_file_name);
void	ft_error(char *str);

#endif

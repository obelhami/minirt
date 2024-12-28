NAME 		= minirt

MEND_FILES = main.c ft_strstr.c ft_strcmp.c ft_isdigit.c ft_atof.c \
			ft_free.c get_next_line/get_next_line.c  \
			get_next_line/get_next_line_utils.c ft_ft_split.c \
			window_funcs.c vector_utils.c setup_3d_world.c render.c \
			degrees_to_radians.c world_funcs.c sphere_funcs.c ft_dblptrlen.c \
			parsing_utils.c random.c plane_funcs.c cylinder_funcs.c \
			rec_utils.c cylinder_funcs_utils.c color_utils.c \
			ray_funcs.c comparisons.c light_funcs.c create_cylinder.c \
			create_plane.c utils_for_parsing.c create_light.c create_camera.c \
			create_ambient.c parsing.c
SRCS = $(addprefix src/, $(MEND_FILES))
OBJS = $(SRCS:.c=.o)
LIBFT 		= src/libft/libft.a
HEADER		= includes/minirt.h

CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror -I includes #-g3 -fsanitize=address
MFLAGS		= -Lsrc/mlx_clone -lmlx -Isrc/mlx_clone -lXext -lX11 -lm -flto
OPT			= -O3 -flto -march=native -ffast-math -fno-math-errno \
			  -funroll-loops -fexpensive-optimizations
RM 			= rm -f


all: 		$(NAME)

$(NAME): 	$(LIBFT) $(OBJS) $(HEADER)
			$(CC) $(CFLAGS) $(OBJS) $(MFLAGS) $(LIBFT) -o $(NAME)

$(LIBFT):
			@$(MAKE) -C src/libft

clean:
			$(RM) $(OBJS)
			$(MAKE) -C src/libft clean

fclean: 	clean
			$(RM) $(NAME)
			$(MAKE) -C src/libft fclean

re: 		fclean $(NAME)

.PHONY: 	all clean fclean re

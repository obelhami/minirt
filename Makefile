NAME 		= minirt

MEND_FILES = main.c ft_strstr.c ft_strcmp.c ft_isdigit.c ft_atof.c \
			ft_free.c ft_add_back.c get_next_line/get_next_line.c  \
			get_next_line/get_next_line_utils.c
SRCS = $(addprefix src/, $(MEND_FILES))
OBJS = $(SRCS:.c=.o)
LIBFT 		= src/libft/libft.a
HEADER		= includes/minirt.h

CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror -I includes #-g3 -fsanitize=address
RM 			= rm -f


all: 		$(NAME)

$(NAME): 	$(LIBFT) $(OBJS) $(HEADER)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
			@$(MAKE) -C libft

clean:
			$(RM) $(OBJS)
			$(MAKE) -C libft clean

fclean: 	clean
			$(RM) $(NAME)
			$(MAKE) -C libft fclean

re: 		fclean $(NAME)

.PHONY: 	all clean fclean re

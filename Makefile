MEND_FILES = main.c ft_strstr.c ft_strcmp.c ft_isdigit.c ft_atof.c \
			
SRCS = $(addprefix mendatory/, $(MEND_FILES))

GNL_FILES = get_next_line.c get_next_line_utils.c
GNL = $(addprefix get_next_line/, $(GNL_FILES))

OBJS = $(SRCS:.c=.o) $(GNL:.c=.o)

NAME 		= minirt
CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror -g -fsanitize=address
RM 			= rm -f

LIBFT 		= libft/libft.a

all: 		$(NAME)

$(NAME): 	$(LIBFT) $(OBJS)
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
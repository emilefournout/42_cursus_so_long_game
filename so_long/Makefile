NAME			=	so_long

NAME_LIBRARY	=	libsolong.a

SRCS		=	render_map.c \
				parse_map.c \
				get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c \
				so_long_utils.c \
				check_map_for_parse.c

OBJS		=	${SRCS:.c=.o}
				
CC			=	gcc

CFLAGS		= -Wall -Wextra -Werror -g 

LDFLAGS		= -L. -lsolong -Lft_printf -lftprintf -Lmlx -lmlx -framework OpenGL -framework AppKit

all: $(NAME_LIBRARY) $(NAME)

$(NAME_LIBRARY): $(OBJS)
	$(MAKE) -C mlx
	$(MAKE) -C ft_printf
	ar rcs $(NAME_LIBRARY) $(OBJS)

%.o: %.c
	$(CC) -Wall -Wextra -Imlx -c -g $< -o $@

$(NAME): solong.c
	$(CC) $(CFLAGS) $(LDFLAGS) solong.c -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C mlx
	$(MAKE) clean -C ft_printf

fclean: clean
		rm -f $(NAME)
		rm -f $(NAME_LIBRARY)

re: fclean all

.PHONY: all clean fclean re

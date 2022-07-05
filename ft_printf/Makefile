NAME		= libftprintf.a

SRCS		=	ft_put_unsigned_nbr.c \
				ft_printf.c \
				ft_print_maj_hexa.c \
				ft_putnbr_f.c \
				ft_putstr_f.c \
				ft_putchar_nret.c

OBJS		= ${SRCS:.c=.o}

RM			= rm -f

CC 			= gcc

CFLAGS		= -Wall -Wextra -Werror
	
all: $(NAME)

$(NAME):	$(OBJS)
	ar crs $(NAME) $(OBJS)
	
clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re

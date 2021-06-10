NAME = libftprintf.a

SRCS =	ft_printf.c \
		utils.c \
		parsing_str.c \
		working_argument.c \
		write_symbol.c \
		argument_s.c \
		argument_c.c \
		utils_two.c \
		argument_d_i.c \
		argument_d_i_u_comp.c \
		argument_u.c \
		argument_x.c \
		argument_p.c \
		ft_printf.h

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all		: $(NAME)

$(NAME)	: $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o : %.c libft.h
	gcc $(CFLAGS) -c $< -o $@

clean   :
	rm -f *.o

fclean	:	clean
	$(RM) $(NAME)

re	    :	fclean all

.PHONY	:	all clean fclean re
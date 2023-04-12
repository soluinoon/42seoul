SRCS	=	ft_printf.c \
		ft_printf_utils.c \
		ft_printf_number.c \
		ft_printf_chr.c

OBJS	=	$(SRCS:.c=.o)

HEADER = ft_printf.h

NAME	=	libftprintf.a
RM	=	rm -f
LIB	=	ar rcus
CC	=	cc
CFLAGS	=	-Wall -Wextra -Werror -I $(HEADER)

all	:	$(NAME)

$(NAME) : $(OBJS)
		$(LIB) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

bonus	:	all

.PHONY	:	all clean fclean re


NAME 		= libft.a

SRCS 		= ./srcs/ft_putchar.c ./srcs/ft_swap.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c

OBJS 		= ${SRCS:.c=.o}

INCLU		= ./includes/

CC 			= gcc

RM			= rm -f

CFLAGS 		= -Wall -Wextra -Werror

.c.o :
			${CC}  -c $< -o $@ -I ${INCLU}

${NAME}:	${OBJS}
			ar rcs $@ ${OBJS}
			
all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re

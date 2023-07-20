
NAME 		= do-op

SRCS 		= ./ft_atoi.c ./oper_set.c ./main.c ./ft_putnbr.c

OBJS 		= ${SRCS:.c=.o}

INCLU		= ./ft.h

CC 			= gcc

RM			= rm -f

CFLAGS 		= -Wall -Wextra -Werror

all:		${NAME}

.c.o :
			${CC} ${CFLAGS} -c $< -o $@ -I ${INCLU}

${NAME}:	${OBJS} 
			${CC} ${CFLAGS} -o ${NAME} ${SRCS} -I ${INCLU}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re

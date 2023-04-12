# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihonkim <jihonkim@42student.42seoul.kr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 19:19:11 by jihonkim          #+#    #+#              #
#    Updated: 2022/12/07 19:19:16 by jihonkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PHILO	=	philo

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra
RM 		=	rm -f

SRC_DIR	=	./srcs/
SRCS	=	arg_controller.c init.c main.c eating_controller.c \
			philos.c dining.c time_utils.c philo_utils.c \
			philo_utils2.c

OBJS	=	$(SRCS:.c=.o)
INCS	=	-I include

all: $(PHILO)

$(PHILO): $(OBJS)
	$(CC) $(CFLAGS) -o $(PHILO) $(OBJS) -lpthread

%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(PHILO)

re: fclean all

.PHONY: all clean fclean re
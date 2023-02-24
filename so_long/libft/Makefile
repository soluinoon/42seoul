# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihonkim <jihonkim@42student.42seoul.kr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/16 19:02:52 by mkim2             #+#    #+#              #
#    Updated: 2022/11/24 22:09:21 by jihonkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = \
	ft_strlen.c \
	ft_strcmp.c	\
	ft_strlcat.c	\
	ft_strndup.c    \
	ft_putstr_fd.c	\
	ft_putchar_fd.c	\
	ft_putnbr_fd.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

$(NAME): $(OBJS)
	ar rcs $@ $^

.PHONY : all, clean, fclean, re

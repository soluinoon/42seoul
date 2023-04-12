# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihonkim <gidrlantk@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/02 14:49:14 by jihonkim          #+#    #+#              #
#    Updated: 2022/10/02 14:50:18 by jihonkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

NAME		=	libft.a
SRCS		=	ft_bzero.c \
				ft_calloc.c \
				ft_isdigit.c \
				ft_putstr_fd.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_strlen.c \
				ft_strncmp.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	ar -cr $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

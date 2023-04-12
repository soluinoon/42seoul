# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihonkim <gidrlantk@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/02 14:50:00 by jihonkim          #+#    #+#              #
#    Updated: 2022/10/02 14:50:18 by jihonkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP		= push_swap

CC				= gcc
CFLAG			= -Wextra -Wall -Werror
RM				= rm -f
AR				= ar cr


P_SRCS_DIR		= ./srcs/
P_SRCS			= push_swap.c ft_parsing.c ft_deque.c sort_utils.c ft_sort_big.c \
					ft_sort_short.c set_s.c set_p.c set_r.c set_rr.c push_swap_utils.c
P_OBJS			= $(P_SRCS:.c=.o)

LIBFT			= libft
LIBFT_FLAGS		= -L $(LIBFT) -lft
INCS			= -I includes -I $(LIBFT)

all: $(LIBFT) $(PUSH_SWAP)

$(LIBFT):
	@make --silent --directory=$(LIBFT)

$(PUSH_SWAP): $(P_OBJS)
	$(CC) $(CFLAG) -o $(PUSH_SWAP) $(P_OBJS) $(LIBFT_FLAGS)

%.o: $(P_SRCS_DIR)%.c
	$(CC) $(CFLAG) -c $< -o $@ $(INCS)

clean:
	@make clean --silent --directory=$(LIBFT)
	$(RM) $(P_OBJS)

fclean: clean
	@make fclean --silent --directory=$(LIBFT)
	$(RM) $(PUSH_SWAP)

re: fclean all

.PHONY: all clean fclean re $(LIBFT)

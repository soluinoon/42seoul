/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <gidrlantk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:52:44 by mkim2             #+#    #+#             */
/*   Updated: 2022/10/02 16:37:15 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_digit(char *str)
{
	long	length;

	length = ft_strlen(str);
	if (length != 0)
	{
		if (ft_isdigit(str[length - 1]) == 0)
			return (0);
	}
	return (1);
}

long	ft_atol(char **str)
{
	long	ret;
	int		sign;

	ret = 0;
	sign = 1;
	if (**str && !(**str == '+' || **str == '-') && !(ft_isdigit(**str)))
		ft_perror(1);
	if (**str == '-')
		sign = -1;
	if (**str == '+' || **str == '-')
	{
		++(*str);
	}
	if (**str && !ft_isdigit(**str))
		ft_perror(1);
	while (ft_isdigit(**str))
	{
		ret = ret * 10 + **str - '0';
		++(*str);
	}
	return ((long)sign * ret);
}

void	copy_argv_deq(int argc, char **argv, t_deq *deq)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ft_parsing(argv[i], deq);
		++i;
	}
	check_dups(deq);
}

void	ft_parsing(char *str, t_deq *deq)
{
	long	ret;

	if (check_digit(str) != 1)
		ft_perror(1);
	while (*str)
	{
		while (*str == ' ' || (9 <= *str && *str <= 13))
			++str;
		if (*str == '\0')
			break ;
		ret = ft_atol(&str);
		if (ret > INT_MAX || ret < INT_MIN)
			ft_perror(1);
		push_back(deq, ret);
	}
}

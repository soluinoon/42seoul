/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:32:36 by jihonkim          #+#    #+#             */
/*   Updated: 2022/02/20 17:48:19 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_stock_str.h"

int	str_length(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	str_cpy(int ac, char **str, char **copy)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ac)
	{	
		copy[i] = malloc(sizeof(char) * (str_length(str[i]) + 1));
		while (str[i][j] != '\0')
		{
			copy[i][j] = str[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	copy[ac] = 0;
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*stk;
	char		**copy_arr;

	i = 0;
	stk = malloc(sizeof(t_stock_str) * (ac + 1));
	copy_arr = malloc(sizeof(char *) * (ac + 1));
	if (stk == 0 || copy_arr == 0)
		return (0);
	str_cpy(ac, av, copy_arr);
	while (i < ac)
	{
		stk[i].size = str_length(av[i]);
		stk[i].str = av[i];
		stk[i].copy = copy_arr[i];
		i++;
	}
	stk[ac].str = 0;
	return (stk);
}	

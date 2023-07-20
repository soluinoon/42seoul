/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:56:26 by jihonkim          #+#    #+#             */
/*   Updated: 2022/02/24 13:38:12 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	count_strs(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
		i++;
	return (i);
}

int	check_cmp(char *str, char *str2)
{
	int	i;

	i = 0;
	while (str[i] != '\0' || str[i] != '\0')
	{
		if (str[i] != str2[i])
			return (str[i] - str2[i]);
		i++;
	}
	return (0);
}

void	bubble(char **tab, int size)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 1;
	while (i < size - 1)
	{
		while (j < size)
		{
			if (check_cmp(tab[j - 1], tab[j]) > 0)
			{
				temp = tab[j];
				tab[j] = tab[j - 1];
				tab[j - 1] = temp;
			}
			j++;
		}
		j = 1;
		i++;
	}
}

void	ft_sort_string_tab(char **tab)
{
	int	str_count;

	str_count = count_strs(tab);
	bubble(tab, str_count);
}	

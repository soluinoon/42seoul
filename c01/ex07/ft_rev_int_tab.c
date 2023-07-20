/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:47:38 by jihonkim          #+#    #+#             */
/*   Updated: 2022/02/09 18:00:43 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	half_size;
	int	size_temp;
	int	temp;

	size_temp = size;
	half_size = size / 2;
	while (size_temp > half_size)
	{
		temp = tab[size - size_temp];
		tab[size - size_temp] = tab[size_temp - 1];
		tab[size_temp - 1] = temp;
		size_temp--;
	}
}

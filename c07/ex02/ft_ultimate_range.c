/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:24:57 by jihonkim          #+#    #+#             */
/*   Updated: 2022/02/23 13:44:19 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*ptr;
	int	leng;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	leng = max - min;
	i = 0;
	ptr = (int *)malloc(sizeof(int) * leng);
	if (ptr <= 0)
	{
		*range = 0;
		return (-1);
	}
	while (i < leng)
	{
		ptr[i] = min + i;
		i++;
	}
	*range = ptr;
	return (leng);
}	

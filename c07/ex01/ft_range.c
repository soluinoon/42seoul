/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:19:16 by jihonkim          #+#    #+#             */
/*   Updated: 2022/02/22 19:53:26 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	leng;
	int	*ptr;

	if (min >= max)
		return (0);
	i = 0;
	leng = max - min;
	ptr = (int *)malloc(leng);
	if (!ptr)
		return (0);
	while (i < leng)
	{
		ptr[i] = min + i;
		i++;
	}
	return (ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:42:17 by jihonkim          #+#    #+#             */
/*   Updated: 2022/04/29 16:08:37 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void	*ptr, int value, size_t num)
{
	size_t			i;
	unsigned char	value_temp;
	unsigned char	*ptr_temp;

	value_temp = (unsigned char)value;
	ptr_temp = (unsigned char *)ptr;
	i = 0;
	while (i < num)
	{
		ptr_temp[i] = value_temp;
		i++;
	}
	return (ptr_temp);
}

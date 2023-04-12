/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:15:37 by jihonkim          #+#    #+#             */
/*   Updated: 2022/04/29 19:53:43 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	size_t			i;
	unsigned char	*ptr_temp;

	ptr_temp = (unsigned char *)ptr;
	i = 0;
	while (i < num)
	{
		if (ptr_temp[i] == (unsigned char)value)
			return ((void *)&ptr[i]);
		i++;
	}
	return (0);
}

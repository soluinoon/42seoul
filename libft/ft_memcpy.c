/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:17:13 by jihonkim          #+#    #+#             */
/*   Updated: 2022/04/29 21:20:36 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_temp;
	unsigned char	*src_temp;
	size_t			i;

	if (!dst && !src)
		return (0);
	dst_temp = (unsigned char *)dst;
	src_temp = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst_temp[i] = src_temp[i];
		i++;
	}
	return (dst_temp);
}

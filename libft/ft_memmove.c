/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:23:06 by jihonkim          #+#    #+#             */
/*   Updated: 2022/04/30 03:57:31 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t num)
{
	unsigned char	*dst_temp;
	unsigned char	*src_temp;
	size_t			i;

	if (num <= 0 || dst == src)
		return (dst);
	i = 0;
	dst_temp = (unsigned char *)dst;
	src_temp = (unsigned char *)src;
	if (dst <= src)
	{
		while (num--)
			*dst_temp++ = *src_temp++;
	}
	else
	{
		while (num--)
			*(dst_temp + num) = *(src_temp + num);
	}
	return (dst);
}

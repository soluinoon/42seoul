/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:06:08 by jihonkim          #+#    #+#             */
/*   Updated: 2022/04/29 19:58:08 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *dest, const void *src, size_t num)
{
	size_t				i;
	const unsigned char	*dst_temp;
	const unsigned char	*src_temp;

	i = 0;
	dst_temp = (unsigned char *)dest;
	src_temp = (unsigned char *)src;
	while (i < num)
	{
		if (dst_temp[i] != src_temp[i])
			return (dst_temp[i] - src_temp[i]);
		i++;
	}
	return (0);
}

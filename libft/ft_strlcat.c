/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:51:03 by jihonkim          #+#    #+#             */
/*   Updated: 2022/04/30 05:04:05 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t			i;
	size_t			src_length;
	size_t			dst_length;
	size_t			dst_temp;

	i = 0;
	src_length = ft_strlen(src);
	dst_length = ft_strlen(dest);
	if (size <= dst_length)
		return (size + src_length);
	dst_temp = dst_length;
	while (src[i] != '\0' && dst_temp + 1 < size)
	{
		dest[dst_temp] = src[i];
		dst_temp++;
		i++;
	}
	dest[dst_temp] = '\0';
	return (dst_length + src_length);
}

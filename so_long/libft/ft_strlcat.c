/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@42student.42seoul.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:03:26 by mkim2             #+#    #+#             */
/*   Updated: 2022/11/24 14:14:07 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;

	dst_len = ft_strlen(dst);
	if (dst_len >= dstsize)
		return (ft_strlen(src) + dstsize);
	while (dst_len < dstsize - 1 && *src != '\0')
		dst[dst_len++] = *(src++);
	dst[dst_len] = '\0';
	return (dst_len);
}

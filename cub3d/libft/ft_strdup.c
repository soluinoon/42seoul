/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:45:59 by hwichoi           #+#    #+#             */
/*   Updated: 2023/03/07 18:46:44 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dst;
	size_t	len_src;
	size_t	len_dst;

	len_src = ft_strlen(src);
	len_dst = 0;
	dst = (char *)malloc(sizeof(char) * (len_src + 1));
	if (!dst)
		return (NULL);
	while (len_dst < len_src && src[len_dst] != '\0')
	{
		dst[len_dst] = src[len_dst];
		len_dst++;
	}
	dst[len_dst] = '\0';
	return (dst);
}

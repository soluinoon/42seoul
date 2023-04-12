/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:46:04 by hwichoi           #+#    #+#             */
/*   Updated: 2023/03/07 18:46:44 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size_d;
	size_t	size_s;
	size_t	i;

	i = 0;
	size_d = ft_strlen(dst);
	size_s = ft_strlen(src);
	if (size == 0)
		return (size_s);
	if (size < size_d)
	{
		return (size + size_s);
	}
	else
	{
		while (src[i] != '\0' && (size_d + 1 + i) < size)
		{
			dst[size_d + i] = src[i];
			i++;
		}
		dst[size_d + i] = '\0';
		return (size_d + size_s);
	}
}

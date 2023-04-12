/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:48:55 by jihonkim          #+#    #+#             */
/*   Updated: 2022/04/29 22:17:35 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h" 

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_length;
	size_t	i;

	i = 0;
	src_length = ft_strlen(src);
	if (size == 0)
		return (src_length);
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_length);
}

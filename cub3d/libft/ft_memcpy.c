/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:45:36 by hwichoi           #+#    #+#             */
/*   Updated: 2023/03/07 18:46:44 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_new;
	unsigned char	*src_new;

	dest_new = (unsigned char *)dest;
	src_new = (unsigned char *)src;
	if (!dest_new && !src_new)
		return (NULL);
	while (n--)
	{
		*dest_new++ = *src_new++;
	}
	return (dest);
}

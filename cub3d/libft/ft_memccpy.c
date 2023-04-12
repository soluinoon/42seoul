/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:45:29 by hwichoi           #+#    #+#             */
/*   Updated: 2023/03/07 18:46:44 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*dest_new;
	unsigned char	*src_new;

	dest_new = (unsigned char *) dest;
	src_new = (unsigned char *) src;
	while (n > 0)
	{
		*dest_new = *src_new;
		if (*src_new == (unsigned char) c)
		{
			return (++dest);
		}
		dest_new++;
		src_new++;
		dest++;
		n--;
	}
	return (NULL);
}

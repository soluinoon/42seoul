/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:45:41 by hwichoi           #+#    #+#             */
/*   Updated: 2023/03/07 18:46:44 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*d;

	d = (unsigned char *)s;
	while (n--)
	{
		*d++ = (unsigned char) c;
	}
	return (s);
}

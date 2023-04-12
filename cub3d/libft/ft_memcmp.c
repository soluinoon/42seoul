/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:45:34 by hwichoi           #+#    #+#             */
/*   Updated: 2023/03/07 18:46:44 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s, const void *d, size_t n)
{
	unsigned char	*s_new;
	unsigned char	*d_new;

	s_new = (unsigned char *)s;
	d_new = (unsigned char *)d;
	while (n && (*s_new == *d_new))
	{
		s_new++;
		d_new++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*s_new - *d_new);
}

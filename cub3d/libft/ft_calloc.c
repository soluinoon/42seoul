/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:44:54 by hwichoi           #+#    #+#             */
/*   Updated: 2023/03/07 18:46:43 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*dst;

	dst = (char *)malloc(n * size);
	if (!dst)
		return (NULL);
	ft_memset(dst, 0, (n * size));
	return (dst);
}

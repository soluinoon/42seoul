/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:14:03 by jihonkim          #+#    #+#             */
/*   Updated: 2022/04/30 09:09:50 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s_temp;
	size_t			i;

	s_temp = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		s_temp[i] = 0;
		i++;
	}
}

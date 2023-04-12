/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:46:02 by hwichoi           #+#    #+#             */
/*   Updated: 2023/03/07 18:46:44 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s, const char *d)
{
	int		i;
	char	*dst;

	i = 0;
	if (!s || !d)
		return (NULL);
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s) + ft_strlen(d) + 1));
	if (!dst)
		return (NULL);
	while (*s)
		dst[i++] = *s++;
	while (*d)
		dst[i++] = *d++;
	dst[i] = '\0';
	return (dst);
}

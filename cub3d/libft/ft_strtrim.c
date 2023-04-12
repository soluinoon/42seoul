/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:46:30 by hwichoi           #+#    #+#             */
/*   Updated: 2023/03/07 18:46:45 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s, const char *set)
{
	char	*d;
	size_t	i;

	d = NULL;
	if (s && set)
	{
		while (*s && ft_strchr(set, *s))
			s++;
		i = ft_strlen(s);
		while (i && ft_strchr(set, s[i]))
			i--;
		d = ft_substr(s, 0, i + 1);
	}
	return (d);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:46:24 by hwichoi           #+#    #+#             */
/*   Updated: 2023/03/07 18:46:44 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*new_big;
	char	*new_little;

	new_big = (char *)big;
	new_little = (char *)little;
	i = 0;
	if (ft_strlen(new_little) == '\0')
		return (new_big);
	while (i < len && new_big[i])
	{
		j = 0;
		while (((i + j) < len) && (new_big[i + j] == new_little[j]) \
				&& new_little[j])
			j++;
		if (new_little[j] == '\0')
			return (new_big + i);
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:18:14 by jihonkim          #+#    #+#             */
/*   Updated: 2022/04/30 05:49:23 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	j;
	size_t	i;
	size_t	find_len;

	if (!(*find))
		return ((char *)str);
	find_len = ft_strlen(find);
	i = 0;
	while (i < len && *str != '\0')
	{
		j = 0;
		while ((*(str + j) == *(find + j)) && (*(find + j) != '\0' \
		&& (j + i < len)))
			j++;
		if (j == find_len)
			return ((char *)str);
		str++;
		i++;
	}
	return (0);
}

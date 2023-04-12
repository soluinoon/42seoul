/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:46:32 by hwichoi           #+#    #+#             */
/*   Updated: 2023/03/07 18:46:45 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *str, unsigned int start, size_t size)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	if (start >= ft_strlen(str))
		return (ft_strdup(""));
	substr = (char *)malloc(sizeof(char) * (size + 1));
	if (!substr)
		return (NULL);
	str += start;
	while (i < size && *str)
	{
		substr[i] = *str++;
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:35:52 by jihonkim          #+#    #+#             */
/*   Updated: 2022/04/29 23:47:09 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	sub_len;
	char			*sub;

	if (!s)
		return (0);
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	sub_len = (unsigned int)ft_strlen(s) - start;
	i = 0;
	if (sub_len <= len)
		len = sub_len;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (0);
	while (i < len)
	{
		sub[i] = s[start];
		start++;
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 12:03:09 by jihonkim          #+#    #+#             */
/*   Updated: 2022/04/30 08:01:44 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	str_len;
	size_t	i;

	if (!s || !f)
		return (0);
	str_len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!str)
		return (0);
	i = 0;
	while (i < str_len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

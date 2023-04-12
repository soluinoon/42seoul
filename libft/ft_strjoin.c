/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:41:35 by jihonkim          #+#    #+#             */
/*   Updated: 2022/04/30 08:04:59 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	str_count;
	char	*str;

	if (!s1 || !s2)
		return (0);
	i = 0;
	str_count = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (0);
	while (s1[i] != '\0')
		str[str_count++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		str[str_count++] = s2[i++];
	str[str_count] = '\0';
	return (str);
}

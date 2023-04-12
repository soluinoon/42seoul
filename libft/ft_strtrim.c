/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:17:42 by jihonkim          #+#    #+#             */
/*   Updated: 2022/04/30 03:20:00 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	check_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	begin;
	size_t	end;
	size_t	i;
	char	*str;

	if (!s1)
		return (0);
	if (!set)
		return ((char *)s1);
	begin = 0;
	end = ft_strlen(s1);
	while (s1[begin] && check_set(s1[begin], set) == 1)
		begin++;
	while (end > 0 && s1[end - 1] != '\0' && check_set(s1[end - 1], set) == 1)
		end--;
	if (begin > end)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (end - begin + 1));
	if (!str)
		return (0);
	i = 0;
	while (begin < end)
		str[i++] = s1[begin++];
	str[i] = '\0';
	return (str);
}

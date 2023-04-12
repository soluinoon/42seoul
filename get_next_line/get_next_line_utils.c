/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:08:43 by jihonkim          #+#    #+#             */
/*   Updated: 2022/07/20 11:43:40 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
	{
		return (0);
	}
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char) c)
		{
			return ((char *)&str[i]);
		}		
		i++;
	}
	return (0);
}

void	sub_join(char *str, char *s1, char *s2)
{
	int	i;
	int	str_count;

	str_count = 0;
	i = 0;
	while (s1[i] != '\0')
		str[str_count++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		str[str_count++] = s2[i++];
	str[str_count] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	sub_join(str, s1, s2);
	free(s1);
	return (str);
}

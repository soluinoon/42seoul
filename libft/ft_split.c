/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 20:02:50 by jihonkim          #+#    #+#             */
/*   Updated: 2022/04/30 07:54:48 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	free_strs(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i] != 0)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static size_t	fill_it(char **strs, char const *str, size_t size, size_t index)
{
	size_t	i;

	strs[index] = malloc(sizeof(char) * (size + 1));
	if (strs[index] == 0)
	{
		free_strs(strs);
		return (0);
	}
	i = 0;
	while (i < size)
	{
		strs[index][i] = str[i];
		i++;
	}
	strs[index][i] = '\0';
	return (1);
}

static size_t	how_many_strs(char const *str, char c)
{
	size_t	arr_size;

	arr_size = 0;
	while (*str != '\0')
	{
		if (*str != c)
		{
			arr_size++;
			while (*str != '\0' && *str != c)
				str++;
			str--;
		}
		str++;
	}
	return (arr_size);
}

static char	**make_strs(char const *str, char c, size_t *size)
{
	char	**strs;

	if (!str)
		return (0);
	*size = how_many_strs(str, c);
	strs = malloc(sizeof(char *) * (*size + 1));
	if (strs == 0)
		return (0);
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	size_t		counter;
	size_t		i;
	size_t		str_getsoo;
	char		**strs;

	strs = make_strs(s, c, &str_getsoo);
	if (strs == 0)
		return (0);
	counter = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			i = 0;
			while (*(s + i) != '\0' && *(s + i) != c)
				i++;
			if (fill_it(strs, s, i, counter++) == 0)
				return (0);
			s += i - 1;
		}
		s++;
	}
	strs[str_getsoo] = 0;
	return (strs);
}

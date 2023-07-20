/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 20:02:50 by jihonkim          #+#    #+#             */
/*   Updated: 2022/02/23 14:31:48 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
int	check_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	how_many_strs(char *str, char *charset)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		if (check_charset(str[i], charset) == 0)
		{
			counter++;
			while (str[i] != '\0' && check_charset(str[i], charset) == 0)
				i++;
		}
		i++;
	}
	return (counter);
}

char	*fill_it(char *str, char *charset, int index)
{
	char	*arr;
	int		arr_size;
	int		i;
	int		j;

	i = index;
	arr_size = 0;
	while (str[i] != '\0' && check_charset(str[i], charset) == 0)
	{
		arr_size++;
		i++;
	}
	j = 0;
	arr = (char *)malloc(arr_size + 1);
	if (!arr)
		return (0);
	while (j < arr_size)
		arr[j++] = str[index++];
	arr[arr_size] = '\0';
	return (arr);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		str_getsoo;
	char	**re_arr;

	str_getsoo = how_many_strs(str, charset);
	i = 0;
	j = 0;
	re_arr = (char **)malloc(sizeof(char *) * str_getsoo + 1);
	if (!re_arr)
		return (0);
	while (str[i] != '\0')
	{
		if (check_charset(str[i], charset) == 0)
		{
			re_arr[j++] = fill_it(str, charset, i);
			while (str[i] != '\0' && check_charset(str[i], charset) == 0)
				i++;
		}
		i++;
	}
	re_arr[str_getsoo] = 0;
	return (re_arr);
}

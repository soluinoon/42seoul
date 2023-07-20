/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 21:15:04 by jihonkim          #+#    #+#             */
/*   Updated: 2022/02/23 11:26:55 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	str_length2(char *arr)
{
	int	i;

	i = 0;
	while (arr[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	make_re_arr(int size, char **strs, char *sep, char *re_arr)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (i < size)
	{
		while (strs[i][j] != '\0')
			re_arr[k++] = strs[i][j++];
		j = 0;
		while (sep[j] != '\0' && i < (size - 1))
			re_arr[k++] = sep[j++];
		j = 0;
		i++;
	}
}

char	*ft_paste_arr(int size, int size_arr, char **strs, char *sep)
{
	int		i;
	char	*re_arr;

	i = 0;
	re_arr = (char *)malloc(sizeof(char) * (size_arr + 1));
	if (!re_arr)
		return (0);
	make_re_arr(size, strs, sep, re_arr);
	re_arr[size_arr] = '\0';
	return (re_arr);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*arr;
	int		size_arr;
	int		i;

	if (size == 0)
	{	
		arr = (char *)malloc(sizeof(char) * 1);
		if (!(arr))
			return (0);
		return (arr);
	}
	i = 0;
	size_arr = 0;
	while (i < size)
		size_arr += str_length2(strs[i++]);
	i = 0;
	while (i < size - 1)
	{
		size_arr += str_length2(sep);
		i++;
	}
	arr = ft_paste_arr(size, size_arr, strs, sep);
	return (arr);
}

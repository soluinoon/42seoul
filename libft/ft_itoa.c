/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:17:30 by jihonkim          #+#    #+#             */
/*   Updated: 2022/04/30 08:21:54 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	arr_len(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*arr;
	int		size;
	long	n_temp;

	size = arr_len(n);
	arr = (char *)malloc(sizeof(char) * (size + 1));
	if (!arr)
		return (0);
	n_temp = n;
	if (n_temp < 0)
	{
		arr[0] = '-';
		n_temp = -n_temp;
	}
	if (n_temp == 0)
		arr[0] = '0';
	arr[size] = '\0';
	size--;
	while (n_temp)
	{
		arr[size--] = n_temp % 10 + '0';
		n_temp = n_temp / 10;
	}
	return (arr);
}		

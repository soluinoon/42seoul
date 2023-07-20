/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:39:37 by jihonkim          #+#    #+#             */
/*   Updated: 2022/02/23 12:15:35 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	str_check_length(char *arr)
{
	int	i;
	int	ascii[257];
	int	index;
	int	j;

	i = 0;
	while (i < 257)
		ascii[i++] = 0;
	j = 0;
	while (arr[j] != '\0')
	{
		if (arr[j] == '-' || arr[j] == '+' || arr[j] == ' ')
			return (-1);
		index = arr[j++] + '0';
		ascii[index]++;
	}
	if (j == 0 || j == 1)
		return (-1);
	i = 0;
	while (i < 257)
		if (ascii[i++] > 1)
			return (-1);
	return (j);
}

char	check_in_base(char check, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (check == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	minus_and_space(char *str, int *index)
{
	int	i;
	int	minus_counter;

	minus_counter = 1;
	i = *index;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus_counter *= -1;
		i++;
	}
	*index = i;
	return (minus_counter);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	minus_counter;
	int	value;
	int	length;

	i = 0;
	length = str_check_length(base);
	minus_counter = 1;
	value = 0;
	if (length == -1)
		return (0);
	else
	{
		minus_counter = minus_and_space(str, &i);
		while (check_in_base(str[i], base) != -1)
		{
			value = value * length + check_in_base(str[i], base);
			i++;
		}
		return (value * minus_counter);
	}
	return (0);
}

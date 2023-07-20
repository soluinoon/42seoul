/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:27:38 by jihonkim          #+#    #+#             */
/*   Updated: 2022/02/23 19:23:22 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

int	ft_atoi(char *str)
{
	int	i;
	int	minus_counter;
	int	value;

	i = 0;
	minus_counter = 1;
	value = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus_counter *= -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		value = value * 10 + (str[i] - '0');
		i++;
	}
	return (minus_counter * value);
}

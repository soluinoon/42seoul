/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:27:38 by jihonkim          #+#    #+#             */
/*   Updated: 2022/04/30 09:09:34 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *str)
{
	int			minus;
	long		value;
	int			j;
	int			i;

	minus = 1;
	value = 0;
	j = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			minus *= -1;
	while (str[i] <= '9' && str[i] >= '0')
	{
		value = value * 10 + (str[i] - '0');
		j++;
		i++;
		if ((j > 19 && minus == -1) || (value < 0 && minus == -1))
			return ((int)(-9223372036854775807 - 1));
		else if ((j > 19 && minus == 1) || (value < 0 && minus == 1))
			return ((int)9223372036854775807);
	}
	return ((int)value * minus);
}

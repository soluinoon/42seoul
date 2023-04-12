/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:44:50 by hwichoi           #+#    #+#             */
/*   Updated: 2023/03/07 18:46:43 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*str && (*str == ' ' || *str == '\n' || \
				*str == '\t' || *str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	if (*str == '-')
		sign = -sign;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	if (sign < 0)
		res *= sign;
	return (res);
}

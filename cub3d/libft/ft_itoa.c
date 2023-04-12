/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:45:26 by hwichoi           #+#    #+#             */
/*   Updated: 2023/03/07 18:46:44 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lensize(int n)
{
	int	len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n != 0)
	{
		n /= 10;
		++len;
	}
	return (len);
}

static unsigned int	ft_uns(int n)
{
	if (n > 0)
		return (n);
	else
		return (-n);
}

static int	ft_num(int n)
{
	if (n >= 0)
		return (1);
	else
		return (0);
}

char	*ft_itoa(int n)
{
	int				neg;
	unsigned int	num;
	char			*str;
	int				len;

	len = ft_lensize(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	num = ft_uns(n);
	neg = ft_num(n);
	str[len--] = '\0';
	while (num && len)
	{
		str[len--] = num % 10 + '0';
		num = num / 10;
	}
	str[len] = num % 10 + '0';
	if (neg == 0)
		str[0] = '-';
	return (str);
}

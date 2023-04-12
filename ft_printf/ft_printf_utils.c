/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@42student.42seoul.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:13:44 by jihonkim          #+#    #+#             */
/*   Updated: 2022/08/27 15:13:55 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*get_base(const char c)
{
	if (c == 'u' || c == 'd' || c == 'i')
		return ("0123456789");
	else if (c == 'x' || c == 'p')
		return ("0123456789abcdef");
	else if (c == 'X')
		return ("0123456789ABCDEF");
	return (0);
}

int	itoa_cnt(const char c, char *num_str, unsigned long long num, int base)
{
	int		cnt;
	char	*base_inf;

	cnt = 0;
	if (num == 0)
	{
		num_str[cnt] = '0';
		cnt++;
	}
	else
	{
		base_inf = get_base(c);
		while (num != 0)
		{
			num_str[cnt] = base_inf[num % base];
			num = num / base;
			cnt++;
		}
	}
	return (cnt);
}

int	print_num(long long num, const char c, int base)
{
	int		cnt;
	int		len;
	char	num_str[17];

	cnt = 0;
	len = itoa_cnt(c, num_str, num, base);
	while (len-- > 0)
	{
		cnt += write(1, &num_str[len], 1);
	}
	return (cnt);
}

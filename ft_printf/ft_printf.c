/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@42student.42seoul.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:13:46 by jihonkim          #+#    #+#             */
/*   Updated: 2022/08/27 15:13:55 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_check(va_list ap, char c)
{
	int	res;

	res = 0;
	if (c == 'c')
		res += print_chr(ap);
	else if (c == 's')
		res += print_str(ap);
	else if (c == 'p')
		res += print_mem(ap, c);
	else if (c == 'd')
		res += print_int(ap, c);
	else if (c == 'i')
		res += print_int(ap, c);
	else if (c == 'u')
		res += print_uint(ap, c);
	else if (c == 'x')
		res += print_hexa(ap, c);
	else if (c == 'X')
		res += print_hexa(ap, c);
	else if (c == '%')
		res += write(1, "%", 1);
	return (res);
}

int	printing(va_list ap, const char *format)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			res += format_check(ap, format[i]);
			if (format[i] == '\0')
				break ;
		}
		else
			res += write(1, &format[i], 1);
		i++;
	}
	return (res);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		print_cnt;

	print_cnt = 0;
	va_start(ap, format);
	print_cnt = printing(ap, format);
	va_end(ap);
	return (print_cnt);
}

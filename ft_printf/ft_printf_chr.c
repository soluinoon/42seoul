/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@42student.42seoul.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:13:40 by jihonkim          #+#    #+#             */
/*   Updated: 2022/08/27 15:13:55 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_chr(va_list ap)
{
	char	c;

	c = (unsigned char)va_arg(ap, int);
	write(1, &c, 1);
	return (1);
}

int	print_str(va_list ap)
{
	int		res;
	char	*str;

	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	res = ft_strlen(str);
	write(1, str, res);
	return (res);
}

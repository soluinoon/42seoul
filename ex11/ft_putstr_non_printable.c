/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:40:04 by jihonkim          #+#    #+#             */
/*   Updated: 2022/02/13 19:32:19 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	change_hex(char s)
{
	unsigned char	num;
	unsigned char	ber;
	char			*hex;

	hex = "0123456789";
	num = s / 16;
	ber = s % 16;
	write(1, "\\", 1);
	write(1, &hex[num], 1);
	write(1, &hex[ber], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] < 127) && (str[i] > 31)))
			change_hex(str[i]);
		else
			write(1, &str[i], 1);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 11:15:23 by jihonkim          #+#    #+#             */
/*   Updated: 2022/02/06 20:54:20 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	check_comb(int a)
{
	char	char_one;
	char	char_ten;
	char	char_hund;

	if (((a % 100 % 10) > (a % 100 / 10)) && ((a % 100 / 10) > (a / 100)))
	{
		char_hund = (a / 100) + '0';
		char_ten = (a % 100 / 10) + '0';
		char_one = (a % 100 % 10) + '0';
		write(1, ", ", 2);
		write(1, &char_hund, 1);
		write(1, &char_ten, 1);
		write(1, &char_one, 1);
	}
}

void	ft_print_comb(void)
{
	int	a;

	a = 13;
	write(1, "012", 3);
	while (a < 1000)
	{
		check_comb(a);
		a++;
	}
}

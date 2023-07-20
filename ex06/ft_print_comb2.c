/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:30:26 by jihonkim          #+#    #+#             */
/*   Updated: 2022/02/06 20:59:50 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_print_real(int number)
{
	char	ch_number;

	if (number < 10)
	{
		ch_number = number + '0';
		write(1, "0", 1);
		write(1, &ch_number, 1);
	}
	else
	{
		ch_number = (number / 10) + '0';
		write(1, &ch_number, 1);
		ch_number = (number % 10) + '0';
		write(1, &ch_number, 1);
	}
}

void	ft_print_comb2(void)
{
	int	first_numb;
	int	second_numb;

	first_numb = 0;
	second_numb = 0;
	while (first_numb < 100)
	{
		while (second_numb < 100)
		{
			if ((first_numb < second_numb) && (first_numb != second_numb))
			{
				ft_print_real(first_numb);
				write(1, " ", 1);
				ft_print_real(second_numb);
				if ((first_numb != 98) || (second_numb != 99))
				{
					write(1, ", ", 2);
				}
			}
			second_numb++;
		}
		second_numb = 0;
		first_numb++;
	}
}

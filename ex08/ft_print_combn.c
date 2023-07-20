/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 11:40:03 by jihonkim          #+#    #+#             */
/*   Updated: 2022/02/06 21:18:53 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	g_count;
int	g_numb_buffer[10];

void	write_comma(int n)
{
	int	counter;
	int	last;

	last = 0;
	counter = 0;
	while (counter < n)
	{
		if (g_numb_buffer[counter] == (10 - n + counter))
		{			
			last++;
		}
		counter++;
	}
	if (last != n)
	{
		write(1, ", ", 2);
	}
}

void	check_comb(int digit, int level)
{
	int		counter;
	char	print_buffer;

	if (level == g_count)
	{
		counter = 0;
		while (counter < g_count)
		{
			print_buffer = g_numb_buffer[counter] + '0';
			write(1, &print_buffer, 1);
			counter++;
		}
		write_comma(g_count);
	}
	else
	{
		counter = digit;
		while (counter < 10)
		{
			g_numb_buffer[level] = counter;
			check_comb(counter + 1, level + 1);
			counter++;
		}
	}
}

void	ft_print_combn(int n)
{
	g_count = n;
	check_comb(0, 0);
}

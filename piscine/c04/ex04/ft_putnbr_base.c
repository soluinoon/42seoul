/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:32:50 by jihonkim          #+#    #+#             */
/*   Updated: 2022/02/21 09:25:01 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
int	ft_howmany(int nb, int length)
{
	int	seg;

	seg = 0;
	while (nb != 0)
	{
		nb = nb / length;
		seg++;
	}
	return (seg);
}

int	ft_square(int seg_counter, int length)
{
	int	multi;

	multi = 1;
	while (seg_counter > 1)
	{
		multi = multi * length;
		seg_counter--;
	}
	return (multi);
}

void	ascii_init(int *ascii)
{	
	int	i;

	i = 0;
	while (i < 257)
	{
		ascii[i] = 0;
		i++;
	}
}

int	str_check_length(char *arr)
{
	unsigned int	i;
	int				ascii[257];
	int				j;
	int				index;

	ascii_init(ascii);
	i = 0;
	while (arr[i] != '\0')
	{
		if (arr[i] == '-' || arr[i] == '+')
			return (-1);
		index = arr[i] + '0';
		ascii[index]++;
		i++;
	}
	j = 0;
	while (j < 257)
	{	
		if (ascii[j] > 1)
			return (-1);
		j++;
	}
	if (i == 0 || i == 1)
		return (-1);
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				length;
	unsigned int	seat;
	unsigned int	multi;
	unsigned int	nbr_temp;

	length = str_check_length(base);
	if (length != -1)
	{
		if (nbr < 0)
		{	
			nbr_temp = nbr * (-1);
			write(1, "-", 1);
		}
		else
			nbr_temp = nbr;
		seat = ft_howmany(nbr_temp, length);
		multi = ft_square(seat, length);
		write(1, &base[nbr_temp / multi], 1);
		while (seat > 1)
		{
			multi = ft_square(seat--, length);
			write(1, &base[nbr_temp % multi / (multi / length)], 1);
		}
	}
}

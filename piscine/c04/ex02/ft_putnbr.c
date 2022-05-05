/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:34:14 by jihonkim          #+#    #+#             */
/*   Updated: 2022/02/17 13:57:34 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_howmany(int nb)
{
	int	seg;

	seg = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		seg++;
	}
	return (seg);
}

int	ft_square2(int seg_counter)
{
	int	multi;

	multi = 1;
	while (seg_counter > 1)
	{
		multi = multi * 10;
		seg_counter--;
	}
	return (multi);
}

void	ft_putnbr(int nb)
{
	int				multi;
	char			cont;
	int				seat;
	unsigned int	super_nb;

	multi = 1;
	super_nb = nb;
	if (nb < 0)
	{
		super_nb = -nb;
		write(1, "-", 1);
	}
	seat = ft_howmany(super_nb);
	multi = ft_square2(seat);
	cont = super_nb / multi + '0';
	write(1, &cont, 1);
	while (seat > 1)
	{
		multi = ft_square2(seat);
		cont = (super_nb % multi / (multi / 10)) + '0';
		write(1, &cont, 1);
		seat--;
	}
}

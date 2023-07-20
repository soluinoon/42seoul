/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:29:06 by jihonkim          #+#    #+#             */
/*   Updated: 2022/02/24 09:28:00 by jihonkim         ###   ########.fr       */
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

int	ft_square(int seg_counter)
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
	int		multi;
	char	cont;
	int		seat;
	unsigned int	super_nb;

	multi = 1;
	super_nb = nb;
	if (nb < 0)
	{
		super_nb = -nb;
		write(1, "-", 1);
	}
	seat = ft_howmany(super_nb);
	multi = ft_square(seat);
	cont = super_nb / multi + '0';
	write(1, &cont, 1);
	while (seat > 1)
	{
		multi = ft_square(seat);
		cont = (super_nb % multi / (multi / 10)) + '0';
		write(1, &cont, 1);
		seat--;
	}
}

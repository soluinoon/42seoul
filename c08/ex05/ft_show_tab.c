/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:47:13 by jihonkim          #+#    #+#             */
/*   Updated: 2022/02/22 20:21:11 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_stock_str.h"
#include <unistd.h>

void	write_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
	write(1, "\n", 1);
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
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		write_str(par[i].str);
		ft_putnbr(par[i].size);
		write_str(par[i].copy);
		i++;
	}
}

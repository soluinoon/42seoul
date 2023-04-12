/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:24:06 by jihonkim          #+#    #+#             */
/*   Updated: 2022/04/30 08:22:15 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	n_temp;
	unsigned char	w_temp;

	if (fd < 0)
		return ;
	if (n < 0)
	{
		write(fd, "-", 1);
		n_temp = -n;
	}
	else
		n_temp = n;
	if (n_temp >= 10)
		ft_putnbr_fd(n_temp / 10, fd);
	w_temp = (n_temp % 10) + '0';
	write(fd, &w_temp, 1);
}

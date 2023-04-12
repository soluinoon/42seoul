/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <gidrlantk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:49:53 by jihonkim          #+#    #+#             */
/*   Updated: 2022/11/04 14:17:14 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_perror(void)
{
	ft_putstr_fd("ERROR\n", 2);
	exit(-1);
}

void	ft_ppid(int pid)
{
	ft_putstr_fd("PID : ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
}

void	ft_psuccess(int handler)
{
	(void)handler;
	ft_putstr_fd("Success\n", 1);
}

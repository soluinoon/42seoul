/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <gidrlantk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:54:40 by jihonkim          #+#    #+#             */
/*   Updated: 2022/11/04 19:13:05 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	transmission(int server_pid, char *str)
{
	unsigned char	byte;
	int				i;

	i = 0;
	while (i <= ft_strlen(str))
	{
		byte = 1 << 7;
		while (byte)
		{
			if (str[i] & byte)
			{
				if (kill(server_pid, SIGUSR1) == -1)
					ft_perror();
			}
			else
			{
				if (kill(server_pid, SIGUSR2) == -1)
					ft_perror();
			}
			usleep(150);
			byte = byte >> 1;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	server_pid;

	if (argc != 3)
		ft_perror();
	else
	{
		server_pid = ft_atoi(argv[1]);
		if (ft_atoi_sub(argv[1]) == 0)
			ft_perror();
		if (server_pid > 99998 || server_pid < 100)
			ft_perror();
		if (!argv[1])
			ft_perror();
		signal(SIGUSR1, ft_psuccess);
		transmission(server_pid, argv[2]);
	}
	return (0);
}

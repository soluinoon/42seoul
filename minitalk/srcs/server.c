/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <gidrlantk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:41:56 by jihonkim          #+#    #+#             */
/*   Updated: 2022/11/04 19:12:00 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	receive(int sign, siginfo_t *info, void *context)
{
	static unsigned char	str;
	static unsigned char	cnt;

	(void)context;
	++cnt;
	if (sign == SIGUSR1)
	{
		str = str << 1;
		str += 1;
	}
	else if (sign == SIGUSR2)
		str = str << 1;
	if (cnt == 8)
	{
		ft_putchar_fd(str, 1);
		if (str == 0)
		{
			ft_putchar_fd('\n', 1);
			kill(info->si_pid, SIGUSR1);
		}
		cnt = 0;
		str = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sig;

	pid = getpid();
	ft_ppid(pid);
	sig.sa_sigaction = receive;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}

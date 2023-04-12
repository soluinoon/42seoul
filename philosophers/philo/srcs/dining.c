/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@42student.42seoul.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 14:46:30 by mkim2             #+#    #+#             */
/*   Updated: 2022/12/07 19:16:06 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	waiting_philos(t_info *info)
{
	pthread_mutex_lock(&(info->waiting));
	pthread_mutex_unlock(&(info->waiting));
	if (info->ret_err)
		return (0);
	return (1);
}

void	*do_dining(void *philo)
{
	t_info	*info;
	t_philo	*curr;

	curr = (t_philo *)philo;
	info = curr->info;
	if (!waiting_philos(info))
		return (NULL);
	curr->check_last_eat_time = get_time();
	if (curr->my_seat % 2)
		usleep(10000);
	while (!info->finish && !info->eat_finish)
	{
		if (eating_controller(info, curr))
			break ;
		print_state("is sleeping", info, curr->my_seat);
		check_time(info, 2);
		print_state("is thinking", info, curr->my_seat);
		usleep(100);
	}
	return (NULL);
}

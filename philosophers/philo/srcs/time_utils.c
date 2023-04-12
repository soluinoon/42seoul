/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@42student.42seoul.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 14:46:47 by mkim2             #+#    #+#             */
/*   Updated: 2022/12/07 19:17:20 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long long	get_time(void)
{
	struct timeval	time;
	long long		ret;

	gettimeofday(&time, NULL);
	ret = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (ret);
}

void	check_time(t_info *info, int mode)
{
	long long	dur;
	long long	start;
	long long	curr;
	long long	tmp;

	dur = 0;
	if (mode == 1)
		dur = info->time_to_eat;
	else if (mode == 2)
		dur = info->time_to_sleep;
	tmp = dur * 1000 / 3;
	start = get_time();
	while (!(info->finish))
	{
		curr = get_time();
		if (curr - start >= dur || tmp == 1)
			return ;
		usleep(tmp);
		if (tmp > 750)
			tmp /= 2;
	}
}

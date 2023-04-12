/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@42student.42seoul.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:01:39 by jihonkim          #+#    #+#             */
/*   Updated: 2022/12/07 19:25:32 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_dining	dining;

	if (argc != 5 && argc != 6)
		return (print_err("Error\n"));
	arg_controller(&dining, argc, argv);
	if (!init(&dining))
	{
		free_all(&dining);
		return (-1);
	}
	philos(&dining);
	return (0);
}

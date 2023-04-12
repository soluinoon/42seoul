/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <gidrlantk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:49:35 by jihonkim          #+#    #+#             */
/*   Updated: 2022/10/02 16:42:44 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_deq *deq_a, t_deq *deq_b)
{
	if (deq_a->num < 4)
		ft_shortsort(deq_a, deq_a->num);
	else if (deq_a->num == 5)
		sort_five(deq_a, deq_b);
	else
		sort_atob(deq_a, deq_b, deq_a->num);
}

int	main(int argc, char **argv)
{
	t_deq	deq_a;
	t_deq	deq_b;

	if (1 < argc)
	{
		deq_init(&deq_a);
		deq_init(&deq_b);
		copy_argv_deq(argc, argv, &deq_a);
		push_swap(&deq_a, &deq_b);
		ft_free(&deq_a);
		ft_free(&deq_b);
		return (0);
	}
	else
		return (-1);
}

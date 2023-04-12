/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <gidrlantk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:49:44 by jihonkim          #+#    #+#             */
/*   Updated: 2022/10/02 16:30:16 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_deq *deq)
{
	push_back(deq, pop_front(deq));
	ft_putendl_fd("ra", 1);
	return (1);
}

int	rb(t_deq *deq)
{
	push_back(deq, pop_front(deq));
	ft_putendl_fd("rb", 1);
	return (1);
}

int	rr(t_deq *deq_a, t_deq *deq_b)
{
	push_back(deq_a, pop_front(deq_a));
	push_back(deq_b, pop_front(deq_b));
	ft_putendl_fd("rr", 1);
	return (1);
}

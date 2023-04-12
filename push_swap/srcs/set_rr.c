/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <gidrlantk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:49:48 by jihonkim          #+#    #+#             */
/*   Updated: 2022/10/02 16:30:16 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_deq *deq)
{
	push_front(deq, pop_back(deq));
	ft_putendl_fd("rra", 1);
	return (1);
}

int	rrb(t_deq *deq)
{
	push_front(deq, pop_back(deq));
	ft_putendl_fd("rrb", 1);
	return (1);
}

int	rrr(t_deq *deq_a, t_deq *deq_b)
{
	push_front(deq_a, pop_back(deq_a));
	push_front(deq_b, pop_back(deq_b));
	ft_putendl_fd("rrr", 1);
	return (1);
}

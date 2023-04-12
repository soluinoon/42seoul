/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <gidrlantk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:49:40 by jihonkim          #+#    #+#             */
/*   Updated: 2022/10/02 16:41:01 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_deq *deq_to, t_deq *deq_from)
{
	if (deq_from->next == NULL)
		return (0);
	push_front(deq_to, pop_front(deq_from));
	ft_putendl_fd("pa", 1);
	return (1);
}

int	pb(t_deq *deq_to, t_deq *deq_from)
{
	if (deq_from->next == NULL)
		return (0);
	push_front(deq_to, pop_front(deq_from));
	ft_putendl_fd("pb", 1);
	return (1);
}

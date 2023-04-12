/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <gidrlantk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:49:52 by jihonkim          #+#    #+#             */
/*   Updated: 2022/10/02 16:30:16 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_deq *deq)
{
	int	tmp;

	if (deq->next == NULL || deq->next->rlink == NULL)
		return (0);
	tmp = deq->next->data;
	deq->next->data = deq->next->rlink->data;
	deq->next->rlink->data = tmp;
	ft_putendl_fd("sa", 1);
	return (1);
}

int	sb(t_deq *deq)
{
	int	tmp;

	if (deq->next == NULL || deq->next->rlink == NULL)
		return (0);
	tmp = deq->next->data;
	deq->next->data = deq->next->rlink->data;
	deq->next->rlink->data = tmp;
	ft_putendl_fd("sb", 1);
	return (1);
}

int	ss(t_deq *dq_a, t_deq *dq_b)
{
	int	tmp;

	if (!(dq_a->next == NULL || dq_a->next->rlink == NULL))
	{
		tmp = dq_a->next->data;
		dq_a->next->data = dq_a->next->rlink->data;
		dq_a->next->rlink->data = tmp;
	}
	if (!(dq_a->next == NULL || dq_a->next->rlink == NULL))
	{
		tmp = dq_b->next->data;
		dq_b->next->data = dq_b->next->rlink->data;
		dq_b->next->rlink->data = tmp;
	}
	ft_putendl_fd("ss", 1);
	return (1);
}

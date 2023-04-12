/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_short.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <gidrlantk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:49:28 by jihonkim          #+#    #+#             */
/*   Updated: 2022/10/02 16:41:41 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_deq *deq)
{
	int	bot;
	int	mid;
	int	top;

	bot = deq->next->data;
	mid = deq->next->rlink->data;
	top = deq->next->rlink->rlink->data;
	if (bot < mid && mid < top)
		return ;
	if (bot > mid && mid < top && bot < top)
		sa(deq);
	else if (bot < mid && mid > top && bot < top)
	{
		rra(deq);
		sa(deq);
	}
	else if (bot > mid && bot > top && mid < top)
		ra(deq);
	else if (bot > mid && mid > top)
	{
		ra(deq);
		sa(deq);
	}
	else if (bot < mid && bot > top && mid > top)
		rra(deq);
}

void	ft_shortsort(t_deq *deq, int num)
{
	if (num <= 1)
		return ;
	else if (num == 2 && deq->next->data > deq->next->rlink->data)
		sa(deq);
	else if (num == 3)
		sort_three(deq);
	else
		return ;
}

int	find_pos(t_deq *deq)
{
	int		pos;
	t_node	*tmp;

	pos = 0;
	tmp = deq->next;
	while (tmp)
	{
		if (deq->next->data > tmp->data)
			++pos;
		tmp = tmp->rlink;
	}
	return (pos);
}

void	change_pos(t_deq *deq)
{
	int	pos;

	pos = find_pos(deq);
	if (!pos)
		return ;
	else if (pos == 1)
		sa(deq);
	else if (pos == 2)
	{
		sa(deq);
		ra(deq);
		sa(deq);
		rra(deq);
	}
	else if (pos == 3 && deq->num == 4)
		ra(deq);
	else if (pos == 3 && deq->num == 5)
	{
		rra(deq);
		sa(deq);
		ra(deq);
		ra(deq);
	}
	else
		ra(deq);
}

void	sort_five(t_deq *deq_a, t_deq *deq_b)
{
	pb(deq_b, deq_a);
	pb(deq_b, deq_a);
	sort_three(deq_a);
	pa(deq_a, deq_b);
	change_pos(deq_a);
	pa(deq_a, deq_b);
	change_pos(deq_a);
}

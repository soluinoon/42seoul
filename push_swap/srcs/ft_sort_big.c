/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <gidrlantk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:54:05 by mkim2             #+#    #+#             */
/*   Updated: 2022/10/02 16:43:37 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_pv(t_deq *deq, int cnt, t_cnt *count)
{
	t_node	*tmp;
	int		*arr;
	int		i;

	i = 0;
	tmp = deq->next;
	arr = (int *)malloc(sizeof(int) * cnt);
	if (!arr)
		ft_perror(1);
	while (i < cnt && tmp)
	{
		arr[i] = tmp->data;
		tmp = tmp->rlink;
		++i;
	}
	bubble_sort(arr, cnt);
	count->pv1 = arr[i / 3];
	count->pv2 = arr[i * 2 / 3];
	free(arr);
}

void	rreverse(t_deq *deq_a, t_deq *deq_b, int ra_cnt, int rb_cnt)
{
	int	i;

	i = 0;
	while (i < ra_cnt && i < rb_cnt)
	{
		rrr(deq_a, deq_b);
		++i;
	}
	while (i < ra_cnt)
	{
		rra(deq_a);
		++i;
	}
	while (i < rb_cnt)
	{
		rrb(deq_b);
		++i;
	}
}

void	sort_lowcase(t_deq *deq_a, t_deq *deq_b, int cnt, int flag)
{
	if (flag == 1 && cnt == 2)
	{
		if (deq_a->next->data > deq_a->next->rlink->data)
			sa(deq_a);
	}
	if (flag == 0)
	{
		if (cnt == 1)
			pa(deq_a, deq_b);
		else if (cnt == 2)
		{
			if (deq_b->next->data > deq_b->next->rlink->data)
			{
				pa(deq_a, deq_b);
				pa(deq_a, deq_b);
			}
			else
			{
				sb(deq_b);
				pa(deq_a, deq_b);
				pa(deq_a, deq_b);
			}
		}
	}
}

void	sort_btoa(t_deq *deq_a, t_deq *deq_b, int cnt)
{
	t_cnt	count;

	if (cnt <= 2)
		return (sort_lowcase(deq_a, deq_b, cnt, 0));
	init_cnt(&count);
	find_pv(deq_b, cnt, &count);
	while (cnt--)
	{
		if (deq_b->next->data < count.pv1)
			count.rb_cnt += rb(deq_b);
		else
		{
			count.pa_cnt += pa(deq_a, deq_b);
			if (deq_a->next->data < count.pv2)
				count.ra_cnt += ra(deq_a);
		}
	}
	sort_atob(deq_a, deq_b, count.pa_cnt - count.ra_cnt);
	rreverse(deq_a, deq_b, count.ra_cnt, count.rb_cnt);
	sort_atob(deq_a, deq_b, count.ra_cnt);
	sort_btoa(deq_a, deq_b, count.rb_cnt);
}

void	sort_atob(t_deq *deq_a, t_deq *deq_b, int cnt)
{
	t_cnt	count;

	if (cnt <= 2)
		return (sort_lowcase(deq_a, deq_b, cnt, 1));
	if (check_sorted(deq_a, cnt) == 1)
		return ;
	init_cnt(&count);
	find_pv(deq_a, cnt, &count);
	while (cnt && !remain_all_big(deq_a, cnt, count.pv2))
	{
		if (deq_a->next->data >= count.pv2)
			count.ra_cnt += ra(deq_a);
		else
		{
			count.pb_cnt += pb(deq_b, deq_a);
			if (deq_b->next->data >= count.pv1)
				count.rb_cnt += rb(deq_b);
		}
		cnt--;
	}
	rreverse(deq_a, deq_b, count.ra_cnt, count.rb_cnt);
	count.ra_cnt += cnt;
	sort_atob(deq_a, deq_b, count.ra_cnt);
	sort_btoa(deq_a, deq_b, count.rb_cnt);
	sort_btoa(deq_a, deq_b, count.pb_cnt - count.rb_cnt);
}

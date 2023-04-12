/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <gidrlantk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:49:56 by jihonkim          #+#    #+#             */
/*   Updated: 2022/10/02 16:41:01 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_cnt(t_cnt *count)
{
	count->pv1 = 0;
	count->pv2 = 0;
	count->ra_cnt = 0;
	count->rb_cnt = 0;
	count->pa_cnt = 0;
	count->pb_cnt = 0;
}

void	bubble_sort(int *arr, int cnt)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < cnt)
	{
		j = 0;
		while (j < cnt - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			++j;
		}
		++i;
	}
}

int	check_sorted(t_deq *deq, int cnt)
{
	t_node	*tmp;
	int		i;

	tmp = deq->next;
	i = 1;
	while (i++ < cnt)
	{
		if (tmp->data > tmp->rlink->data)
			return (0);
		tmp = tmp->rlink;
	}
	return (1);
}

int	remain_all_big(t_deq *deq, int cnt, int pv)
{
	int		i;
	t_node	*tmp;

	tmp = deq->next;
	i = 0;
	while (i < cnt)
	{
		if (tmp->data < pv)
			return (0);
		tmp = tmp->rlink;
		++i;
	}
	return (1);
}

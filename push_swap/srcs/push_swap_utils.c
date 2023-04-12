/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <gidrlantk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:01:25 by mkim2             #+#    #+#             */
/*   Updated: 2022/10/02 16:42:02 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_deq *deq)
{
	t_node	*tmp;
	t_node	*del;

	tmp = deq->next;
	while (tmp)
	{
		del = tmp;
		tmp = tmp->rlink;
		free(del);
		del = NULL;
	}
}

void	ft_perror(int n)
{
	if (n == 1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	check_dups(t_deq *deq)
{
	t_node	*cur;
	t_node	*tmp;

	cur = deq->next;
	while (cur)
	{
		tmp = cur->rlink;
		while (tmp)
		{
			if (tmp->data == cur->data)
				ft_perror(1);
			tmp = tmp->rlink;
		}
		cur = cur->rlink;
	}
}

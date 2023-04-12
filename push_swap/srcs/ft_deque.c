/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <gidrlantk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:51:40 by mkim2             #+#    #+#             */
/*   Updated: 2022/10/02 16:30:16 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	deq_init(t_deq *deq)
{
	deq->next = NULL;
	deq->prev = NULL;
	deq->num = 0;
}

void	push_back(t_deq *deq, int item)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		ft_perror(1);
	node->data = item;
	node->llink = deq->prev;
	if (deq->num == 0)
		deq->next = node;
	else
		deq->prev->rlink = node;
	node->rlink = NULL;
	deq->prev = node;
	++(deq->num);
}

void	push_front(t_deq *deq, int item)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		ft_perror(1);
	node->data = item;
	node->rlink = deq->next;
	if (deq->num == 0)
		deq->prev = node;
	else
		deq->next->llink = node;
	node->llink = NULL;
	deq->next = node;
	++(deq->num);
}

int	pop_front(t_deq *deq)
{
	int		item;
	t_node	*node;

	if (deq->num == 0)
		ft_perror(1);
	node = deq->next;
	item = deq->next->data;
	deq->next = deq->next->rlink;
	free(node);
	if (deq->next == NULL)
		deq->prev = NULL;
	else
		deq->next->llink = NULL;
	--(deq->num);
	return (item);
}

int	pop_back(t_deq *deq)
{
	int		item;
	t_node	*node;

	if (deq->num == 0)
		ft_perror(1);
	node = deq->prev;
	item = deq->prev->data;
	deq->prev = deq->prev->llink;
	free(node);
	if (deq->prev == NULL)
		deq->next = NULL;
	else
		deq->prev->rlink = NULL;
	--(deq->num);
	return (item);
}

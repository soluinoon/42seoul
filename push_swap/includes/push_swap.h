/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <gidrlantk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:48:15 by jihonkim          #+#    #+#             */
/*   Updated: 2022/10/02 16:42:22 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include "libft.h"

typedef struct s_cnt
{
	int	pv1;
	int	pv2;
	int	ra_cnt;
	int	rb_cnt;
	int	pa_cnt;
	int	pb_cnt;
}	t_cnt;

typedef struct s_node
{
	long			data;
	struct s_node	*llink;
	struct s_node	*rlink;
}	t_node;

typedef struct s_deque
{
	t_node	*next;
	t_node	*prev;
	int		num;
}	t_deq;

void	deq_init(t_deq *deq);
void	push_back(t_deq *deq, int item);
void	push_front(t_deq *deq, int item);
int		pop_back(t_deq *deq);
int		pop_front(t_deq *deq);

int		pa(t_deq *deq_to, t_deq *deq_from);
int		pb(t_deq *deq_to, t_deq *deq_from);

int		ra(t_deq *deq);
int		rb(t_deq *deq);
int		rr(t_deq *deq_a, t_deq *deq_b);

int		rra(t_deq *deq);
int		rrb(t_deq *deq);
int		rrr(t_deq *deq_a, t_deq *deq_b);

int		sa(t_deq *deq);
int		sb(t_deq *deq);
int		ss(t_deq *deq_a, t_deq *deq_b);

void	sort_three(t_deq *deq);
int		find_pos(t_deq *deq);
void	change_pos(t_deq *deq);
void	sort_five(t_deq *deq_a, t_deq *deq_b);
void	ft_shortsort(t_deq *deq, int num);

void	init_cnt(t_cnt *count);
void	bubble_sort(int *arr, int cnt);
int		check_sorted(t_deq *deq, int cnt);
int		remain_all_big(t_deq *deq, int cnt, int pv);

void	find_pv(t_deq *deq, int cnt, t_cnt *count);
void	rreverse(t_deq *deq_a, t_deq *deq_b, int ra_cnt, int rb_cnt);
void	sort_lowcase(t_deq *deq_a, t_deq *deq_b, int cnt, int flag);
void	sort_btoa(t_deq *deq_a, t_deq *deq_b, int cnt);
void	sort_atob(t_deq *deq_a, t_deq *deq_b, int cnt);

int		check_digit(char *str);
long	ft_atol(char **str);
void	ft_parsing(char *str, t_deq *deq);

void	ft_free(t_deq *deq);
void	ft_perror(int n);
void	check_dups(t_deq *deq);
void	copy_argv_deq(int argc, char **argv, t_deq *deq);

void	push_swap(t_deq *deq_a, t_deq *deq_b);

#endif

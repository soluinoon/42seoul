/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@42student.42seoul.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:16:02 by mkim2             #+#    #+#             */
/*   Updated: 2022/11/24 20:12:06 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <libft.h>

static void	move(t_info *info, int dir)
{
	const int	dy[4] = {0, 1, 0, -1};
	const int	dx[4] = {-1, 0, 1, 0};
	const int	next_y = info->y + dy[dir];
	const int	next_x = info->x + dx[dir];

	if (next_y < 0 || next_x < 0 || next_y >= info->board_h
		|| next_x >= info->board_w)
		return ;
	if (info->board[next_y][next_x] == WALL || (info->board[next_y][next_x]
				== EXIT && info->collectible.count != 0))
		return ;
	if (info->board[next_y][next_x] == EXIT)
		exit_so_long(info, NULL);
	if (info->board[next_y][next_x] == COLLECTIBLE)
		info->collectible.count--;
	info->move_cnt++;
	ft_putnbr_fd(info->move_cnt, 1);
	ft_putstr_fd("\n", 1);
	info->board[info->y][info->x] = EMPTY;
	info->board[next_y][next_x] = PLAYER;
	info->y = next_y;
	info->x = next_x;
	print_player(info, next_x - dx[dir], next_y - dy[dir]);
}

int	key_hook(int key, t_info *info)
{
	if (key == KEY_ESC)
		exit_so_long(info, NULL);
	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		move(info, key % 10);
	return (0);
}

int	mouse_hook(t_info *info)
{
	exit_so_long(info, NULL);
	return (0);
}

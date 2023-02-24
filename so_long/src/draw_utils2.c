/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <gidrlantk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:22:36 by mkim2             #+#    #+#             */
/*   Updated: 2022/11/24 22:20:52 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

void	set_board_data(t_info *info, const char c, int y, int x)
{
	if (c == PLAYER)
	{
		info->player.count++;
		info->y = y;
		info->x = x;
	}
	else if (c == COLLECTIBLE)
		info->collectible.count++;
	else if (c == EXIT)
		info->exit.count++;
}

void	print_board(t_info *info)
{
	int	i;
	int	j;

	i = -1;
	while (++i < info->board_h)
	{
		j = -1;
		while (++j < info->board_w)
			write(1, &info->board[i][j], 1);
		write(1, "\n", 1);
	}
}

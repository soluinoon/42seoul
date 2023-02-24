/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@42student.42seoul.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:25:08 by mkim2             #+#    #+#             */
/*   Updated: 2022/11/24 21:53:56 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

static void	print_image(t_info *info, void *img, int x, int y)
{
	if (img == info->player.img)
		mlx_put_image_to_window(info->mlx, info->win, img, x, y);
	else
		mlx_put_image_to_window(info->mlx, info->win, img, x, y);
}

void	print_init_image(t_info *info)
{
	int	i;
	int	j;

	info->win = mlx_new_window(info->mlx, info->win_w, info->win_h, "jihonkim");
	i = -1;
	while (++i < info->board_w)
	{
		j = -1;
		while (++j < info->board_h)
		{
			if (info->board[j][i] == WALL)
				print_image(info, info->wall.img,
					i * info->background.w, j * info->background.h);
			else
				print_image(info, info->background.img,
					i * info->background.w, j * info->background.h);
			if (info->board[j][i] == COLLECTIBLE)
				print_image(info, info->collectible.img,
					i * info->background.w, j * info->background.h);
			if (info->board[j][i] == EXIT)
				print_image(info, info->exit.img,
					i * info->background.w, j * info->background.h);
		}
	}
	print_player(info, info->x, info->y);
}

void	print_player(t_info *info, int b_x, int b_y)
{
	print_image(info, info->background.img,
		b_x * info->background.w, b_y * info->background.h);
	print_image(info, info->background.img,
		info->x * info->background.w, info->y * info->background.h);
	print_image(info, info->player.img,
		info->x * info->background.w, info->y * info->background.h);
}

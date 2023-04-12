/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:43:45 by hwichoi           #+#    #+#             */
/*   Updated: 2023/03/07 18:44:23 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_close_door(t_glb *glb, int x, int y)
{
	int	x1;
	int	y1;

	x1 = x;
	y1 = y;
	glb->map.map_array[x1][y1] = '2';
}

void	ft_open_door(t_glb *glb, int x, int y)
{
	int	x1;
	int	y1;

	x1 = x;
	y1 = y;
	glb->map.map_array[x1][y1] = '3';
}

void	ft_doors(t_glb *glb)
{
	int	x;
	int	y;

	x = (int)glb->player_x;
	y = (int)glb->player_y;
	if (glb->map.map_array[x][y - 1] == '2' && glb->ctrl.key_open)
		ft_open_door(glb, x, y - 1);
	else if (glb->map.map_array[x][y + 1] == '2' && glb->ctrl.key_open)
		ft_open_door(glb, x, y + 1);
	else if (glb->map.map_array[x + 1][y] == '2' && glb->ctrl.key_open)
		ft_open_door(glb, x + 1, y);
	else if (glb->map.map_array[x - 1][y] == '2' && glb->ctrl.key_open)
		ft_open_door(glb, x - 1, y);
	else if (glb->map.map_array[x][y - 1] == '3' && glb->ctrl.key_open)
		ft_close_door(glb, x, y - 1);
	else if (glb->map.map_array[x][y + 1] == '3' && glb->ctrl.key_open)
		ft_close_door(glb, x, y + 1);
	else if (glb->map.map_array[x + 1][y] == '3' && glb->ctrl.key_open)
		ft_close_door(glb, x + 1, y);
	else if (glb->map.map_array[x - 1][y] == '3' && glb->ctrl.key_open)
		ft_close_door(glb, x - 1, y);
	glb->ctrl.key_open = 0;
}

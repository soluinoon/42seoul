/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@42student.42seoul.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:12:22 by mkim2             #+#    #+#             */
/*   Updated: 2022/11/24 18:08:45 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	validate_extension(t_info *info)
{
	size_t	len;

	len = ft_strlen(info->file_name);
	if (len < 5)
		exit_so_long(info, ERROR_EXTENSION);
	if (ft_strcmp(info->file_name + len - 4, ".ber") != 0)
		exit_so_long(info, ERROR_EXTENSION);
}

void	validate_wall(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->board_h)
		if (info->board[i][0] != WALL ||
				info->board[i][info->board_w - 1] != WALL)
			exit_so_long(info, ERROR_WALL);
	i = -1;
	while (++i < info->board_w)
		if (info->board[0][i] != WALL ||
				info->board[info->board_h - 1][i] != WALL)
			exit_so_long(info, ERROR_WALL);
}

void	validate_invalid_char(t_info *info)
{
	int	i;
	int	j;

	i = -1;
	while (++i < info->board_h)
	{
		j = -1;
		while (++j < info->board_w)
		{
			if (info->board[i][j] == EMPTY)
				continue ;
			if (info->board[i][j] == WALL)
				continue ;
			if (info->board[i][j] == COLLECTIBLE)
				continue ;
			if (info->board[i][j] == EXIT)
				continue ;
			if (info->board[i][j] == PLAYER)
				continue ;
			exit_so_long(info, ERROR_INVALID_CHAR);
		}
	}
}

void	validate_board_data(t_info *info)
{
	if (info->player.count == 0)
		exit_so_long(info, ERROR_NO_PLAYER);
	if (info->exit.count == 0)
		exit_so_long(info, ERROR_NO_EXIT);
	if (info->collectible.count == 0)
		exit_so_long(info, ERROR_NO_COLLECTIBLE);
}

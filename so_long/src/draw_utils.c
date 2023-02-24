/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@42student.42seoul.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:10:18 by mkim2             #+#    #+#             */
/*   Updated: 2022/11/24 20:19:45 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "so_long.h"
#include "libft.h"

static int	read_file_length(char *file_name)
{
	int		fd;
	int		size;
	int		len;
	char	buffer[BUFFER_SIZE];

	size = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit_so_long(NULL, ERROR_FD);
	while (1)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == -1)
		{
			close(fd);
			exit_so_long(NULL, ERROR_FD);
		}
		if (len == 0)
			break ;
		size += len;
	}
	close(fd);
	return (size);
}

static void	create_string(t_info *info)
{
	int		fd;
	int		len;
	char	buffer[BUFFER_SIZE];

	fd = open(info->file_name, O_RDONLY);
	if (fd == -1)
		exit_so_long(NULL, ERROR_FD);
	*info->s = '\0';
	while (1)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == -1)
			exit_so_long(NULL, ERROR_FD);
		if (len == 0)
			break ;
		buffer[len] = '\0';
		ft_strlcat(info->s, buffer, len + 1);
	}
	close(fd);
}

static void	set_board_size(t_info *info)
{
	int	idx;
	int	len;

	idx = -1;
	while (++idx < info->s_size)
		if (info->s[idx] != '\n' && (idx == 0 || info->s[idx - 1] == '\n'))
			info->board_h++;
	idx = -1;
	while (++idx < info->s_size)
	{
		len = 0;
		while (idx < info->s_size && info->s[idx] != '\n')
		{
			idx++;
			len++;
		}
		if (info->board_w == 0)
			info->board_w = len;
		else if (info->board_w != len)
			exit_so_long(info, ERROR_RECTANGLE);
	}
}

static void	set_board(t_info *info)
{
	int	i;
	int	j;
	int	idx;

	info->board = (char **)malloc(sizeof(char *) * (info->board_h + 1));
	if (info->board == NULL)
		exit_so_long(info, ERROR_MALLOC);
	idx = 0;
	i = -1;
	while (++i < info->board_h)
	{
		info->board[i] = (char *)malloc(sizeof(char) * (info->board_w + 1));
		if (info->board[i] == NULL)
			exit_so_long(info, ERROR_MALLOC);
		j = -1;
		while (++j < info->board_w)
		{
			while (info->s[idx] == '\n')
				idx++;
			info->board[i][j] = info->s[idx++];
			set_board_data(info, info->board[i][j], i, j);
		}
	}
}

void	create_board(t_info *info)
{
	info->s_size = read_file_length(info->file_name);
	if (info->s_size < 17)
		exit_so_long(info, ERROR_MAP_SIZE);
	info->s = (char *)malloc(sizeof(char) * (info->s_size + 1));
	if (info->s == NULL)
		exit_so_long(info, ERROR_MALLOC);
	create_string(info);
	set_board_size(info);
	set_board(info);
	validate_board_data(info);
	validate_wall(info);
	validate_invalid_char(info);
	validate_clear(info);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <gidrlantk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:37:37 by hwichoi           #+#    #+#             */
/*   Updated: 2023/03/09 17:10:16 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_file(char **argv)
{
	int	len;

	len = (int)ft_strlen(argv[1]);
	if (argv[1][len - 1] == 'b' && argv[1][len - 2] == 'u' \
				&& argv[1][len - 3] == 'c' && argv[1][len - 4] == '.')
		return ;
	else
		ft_err_exit("bad map file name");
}

void	ft_map_checks(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		ft_err_exit("start must be as ./cub3D ./map_file.cub");
	ft_check_file(argv);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_err_exit("map file not found");
	close(fd);
}

void	ft_err_exit(char *err_msg)
{
	printf("Error: %s\n", err_msg);
	exit (EXIT_FAILURE);
}

void	ft_texture_file_check(char *file_path)
{
	int	fd;

	if (ft_strlen(file_path) < 4)
		ft_err_exit("texture filename is not correct");
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		ft_err_exit("texture file not found");
	close(fd);
}

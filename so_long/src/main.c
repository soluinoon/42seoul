/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@42student.42seoul.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:21:45 by mkim2             #+#    #+#             */
/*   Updated: 2022/11/24 20:14:32 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc == 2)
	{
		init_info(&info, argv[1]);
		validate_extension(&info);
		create_board(&info);
		print_board(&info);
		init_mlx(&info);
		print_init_image(&info);
		mlx_hook(info.win, DESTROY_NOTIFY, 0, mouse_hook, &info);
		mlx_key_hook(info.win, key_hook, &info);
		mlx_loop(info.mlx);
	}
	return (0);
}

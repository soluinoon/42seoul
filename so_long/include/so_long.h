/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <gidrlantk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:27:36 by mkim2             #+#    #+#             */
/*   Updated: 2022/11/24 22:22:07 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_img
{
	void	*img;
	char	*path;
	int		h;
	int		w;
	int		count;
}			t_img;

typedef struct s_info
{
	char	*file_name;
	char	**board;
	char	*s;
	int		s_size;
	int		board_h;
	int		board_w;
	int		move_cnt;
	void	*mlx;
	void	*win;
	int		y;
	int		x;
	int		win_h;
	int		win_w;
	t_img	background;
	t_img	player;
	t_img	wall;
	t_img	exit;
	t_img	collectible;
}			t_info;

# define EMPTY '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

# define DESTROY_NOTIFY 17

# define ERROR_EXTENSION "Error\n extension must be .ber"
# define ERROR_FD "Error\n invalid file descriptor"
# define ERROR_MAP_SIZE "Error\n invalid map size"
# define ERROR_MALLOC "Error\n malloc error"
# define ERROR_WALL "Error\n outside board must be wall"
# define ERROR_RECTANGLE "Error\n board is not rectangle"
# define ERROR_INVALID_CHAR "Error\n invalid character in board"
# define ERROR_NO_PLAYER "Error\n no player on the board"
# define ERROR_NO_EXIT "Error\n no exit on the board"
# define ERROR_NO_COLLECTIBLE "Error\n there is no collectible on the board"
# define ERROR_CANT_CLEAR "Error\n cant clear"

# define PATH_BACKGROUND "./img/background.xpm"
# define PATH_PLAYER "./img/player.xpm"
# define PATH_WALL "./img/wall.xpm"
# define PATH_EXIT "./img/exit.xpm"
# define PATH_COLLECTIBLE "./img/collectible.xpm"

void	exit_so_long(t_info *info, char *s);

void	init_info(t_info *info, char *file_name);
void	init_mlx(t_info *info);

void	validate_extension(t_info *info);
void	validate_wall(t_info *info);
void	validate_invalid_char(t_info *info);
void	validate_board_data(t_info *info);
void	validate_clear(t_info *info);
void	check_table(char **table, t_info *info);
void	flow(char **table, t_info *info, int i, int j);
char	**ft_freeall(char **list);
char	*ft_strndup(const char *s, int n);

void	print_init_image(t_info *info);
void	print_player(t_info *info, int b_x, int b_y);

void	create_board(t_info *info);

void	set_board_data(t_info *info, const char c, int y, int x);
void	print_board(t_info *info);

int		key_hook(int key, t_info *info);
int		mouse_hook(t_info *info);

# define BUFFER_SIZE 1000000
#endif

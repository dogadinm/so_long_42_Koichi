/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:16:04 by mdogadin          #+#    #+#             */
/*   Updated: 2024/01/09 14:38:11 by mdogadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "./minilibx-linux/mlx.h"
#include "libft/libft.h"
# include <fcntl.h>
#include <stdbool.h>
#include <unistd.h>

# define PLAYER "./images/Koich.xpm"
# define COLLECTABLE "./images/strela.xpm"
# define EXIT "./images/proverka_jopy.xpm"
# define WALL "./images/stena.xpm"
# define FLOOR "./images/pol.xpm"
# define FIN_EXIT "./images/Jopu_proveril.xpm"
# define ON_EXIT "./images/Jopu_ne_proveril.xpm"

# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307

# define WIDTH 128
# define HIGHT 128

typedef struct s_img
{
	void	*collectible;
	void	*player;
	void	*floor;
	void	*wall;
	void	*exit;
	void	*fin_exit;
	void	*on_exit;
}	t_img;

typedef struct s_game
{
	t_img img;
	void	*mlx;
	void	*win;
	char	**map;
	char	**map_passability;
	char	temp;
	int		row;
	int		col;
	int		exit;
	int		score;
	int		player;
	int		player_y;
	int		player_x;
	int		end_game;
	int		move;
}	t_game;


int size_row(int fd_x);
int	size_col(int fd_y);
void check_arg(t_game *game, int argc, char **argv);
int	collectible_on_map(t_game *game);
void ft_exit(char *s, t_game *game);
void all_map_checks(t_game *game, int fd_map);
void	free_map_passability(t_game *game);
void player_position(t_game *game);
int	render_img(t_game *game);
int	close_window(t_game *game);
int	move_key(int keycode, t_game *game);
void texturs(t_game *game);
void	free_img(t_game *game);
void free_map(t_game *game);
int	close_window(t_game *game);
void	passability_check(t_game *game , int fd_map);



#endif
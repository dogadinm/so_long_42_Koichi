/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:16:04 by mdogadin          #+#    #+#             */
/*   Updated: 2023/12/21 13:34:04 by mdogadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "./minilibx-linux/mlx_int.h"
#include "./minilibx-linux/mlx.h"
#include "libft/libft.h"
#include <stdbool.h>

typedef struct s_img
{
	void	*collectible;
	void	*player;
	void	*floor;
	void	*wall;
	void	*exit;
	void	*on_exit;
}	t_img;

typedef struct s_game
{
	t_img img;
	void	*mlx;
	void	*win;
	char	**map;
	char	**map_arrangement;
	char	temp;
	int		row;
	int		col;
	int		exit;
	int		score;
	int		player;
	int		player_on_box;
	int		player_y;
	int		player_x;
	int		end_game;
	int		move;
}	t_game;


int size_row(t_game *game, int fd_x);
int	size_col(t_game *game, int fd_y);
void check_arg(t_game *game, int argc, char **argv);
int	collectible_on_map(t_game *game);
void ft_exit(char *s, t_game *game);
void all_map_checks(t_game *game, int fd_map);
void	free_map_arrangement(t_game *game);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:16:04 by mdogadin          #+#    #+#             */
/*   Updated: 2023/12/19 12:13:25 by mdogadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "./minilibx-linux/mlx_int.h"
#include "./minilibx-linux/mlx.h"
#include "libft/libft.h"

typedef struct s_img
{
	void	*collectibale;
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
	char	**map_floodfill;
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

#endif
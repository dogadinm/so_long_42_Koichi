/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:29:15 by mdogadin          #+#    #+#             */
/*   Updated: 2023/12/21 11:59:53 by mdogadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_wall(t_game *game)
{
	int x;
	int y;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[0][y] != '1' || game->map[game->row - 1][y] != '1')
				ft_exit("Error\nThe map is not surrounded by walls", game);
			if (game->map[x][0] != '1' || game->map[x][game->col - 1] != '1')
				ft_exit("Error\nThe map is not surrounded by walls", game);
			y++;
		}
	}
	x++;
}

void map_correct(t_game *game)
{
	int y;
	int x;
	int size;

	y = 0;
	x = 0;
	size = ft_strlen(game->map[0]);
	while (game->map[x] != 0)
	{
		y = ft_strlen(game->map[x]);
		if (y != size)
			ft_exit("Error\nYour map is not rectangular", game);
		x++;
	}
	ft_wall(game);
}

static void	char_check(t_game *game, char c, int x, int y)
{
	if (c == 'C')
		game->score++;
	else if (c == 'E')
		game->exit++;
	else if (c == 'P')
	{
		game->player++;
		game->player_x = x;
		game->player_y = y;
	}
	else if (c == '1' || c == '0')
		return ;
	else
		ft_exit("Error\nInvalid characters", game);
}

void	map_check(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			char_check(game, game->map[x][y], x, y);
			y++;
		}
		x++;
	}
	if (game->score == 0)
		ft_exit("Error\nThere is no collectible", game);
	else if (game->exit == 0)
		ft_exit("Error\nThere is no exit", game);
	else if (game->exit > 1)
		ft_exit("Error\nThere must be at least one exit", game);
	else if (game->player == 0)
		ft_exit("Error\nThere is no player", game);
	else if (game->player > 1)
		ft_exit("Error\nOnly one player on map ", game);

}

void all_map_checks(t_game *game, int fd_map)
{
	ft_printf("Loading!\n");
	map_check(game);
	map_correct(game);
	path_check(game, fd_map);
}
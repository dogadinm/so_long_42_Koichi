/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:41:19 by mdogadin          #+#    #+#             */
/*   Updated: 2023/12/21 13:32:35 by mdogadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_malloc(t_game *game, int fd)
{
	int		i;
	char	*c;
	int		y;

	i = 0;
	y = game->row + 1;
	game->map_arrangement = (char **)malloc(sizeof(char *) * y);
	if (!game->map_arrangement)
		free_img(game);
	while (i < y)
	{
		c = get_next_line(fd);
		game->map_arrangement[i] = ft_strtrim(c, "\n");
		i++;
		free(c);
	}
}

bool	fill(t_game *game, char c, int x, int y)
{
	static bool		exit = false;
	static int		ys = 0;
	
	if (x < 0 || y < 0 || x >= game->row || y >= game->col)
		return (false);
	else if (game->map_arrangement[x][y] == 'X')
		return (false);
	else if (game->map_arrangement[x][y] == '1')
		return (false);
	else if (game->map_arrangement[x][y] == 'E')
		exit = true;
	if (game->map_arrangement[x][y] == 'C')
		ys++;
	game->map_arrangement[x][y] = 'X';
	fill(game, c, x + 1, y);
	fill(game, c, x, y + 1);
	fill(game, c, x - 1, y);
	fill(game, c, x, y - 1);
	return (ys == game->score && exit);
}


int	arrangement(t_game *game)
{
    char	b;
    int	x;
	int	y;
	bool valid;

	b = game->map_arrangement[game->player_x][game->player_y];
	x = game->player_x;
	y = game->player_y;
	valid = fill(game, b, x, y);
	return (valid);
}

void	path_check(t_game *game , int fd_map)
{
    map_malloc(game, fd_map);
    if (!arrangement(game))
	{
		ft_printf ("Error\nInvalid path to on the map\n");
		free_img(game);
		close(fd_map);
	}
	free_map_floodfill(game);
}
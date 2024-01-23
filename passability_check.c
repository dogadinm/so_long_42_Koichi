/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:41:19 by mdogadin          #+#    #+#             */
/*   Updated: 2024/01/09 13:23:38 by mdogadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_test_malloc(t_game *game, int fd)
{
	int		i;
	char	*c;
	int		x;

	i = 0;
	x = game->row + 1;
	game->map_passability = (char **)malloc(sizeof(char *) * x);
	if (!game->map_passability)
		free_img(game);
	while (i < x)
	{
		c = get_next_line(fd);
		game->map_passability[i] = ft_strtrim(c, "\n");
		i++;
		free(c);
	}
}

bool	test(t_game *game, int x, int y)
{
	static bool		exit = false;
	static int		ys = 0;
	
	if (x < 0 || y < 0 || x >= game->row || y >= game->col)
		return (false);
	else if (game->map_passability[x][y] == 'X')
		return (false);
	else if (game->map_passability[x][y] == '1')
		return (false);
	else if (game->map_passability[x][y] == 'E')
		exit = true;
	if (game->map_passability[x][y] == 'C')
		ys++;
	game->map_passability[x][y] = 'X';
	test(game, x + 1, y);
	test(game, x, y + 1);
	test(game, x - 1, y);
	test(game, x, y - 1);
	return (ys == game->score && exit);
}


int	passability(t_game *game)
{
    int	x;
	int	y;
	bool valid;

	x = game->player_x;
	y = game->player_y;
	valid = test(game, x, y);
	return (valid);
}

void	passability_check(t_game *game , int fd_map)
{
    map_test_malloc(game, fd_map);
    if (!passability(game))
	{
		free_map_passability(game);
		close(fd_map);
		ft_exit("Error\nImpossibale to pass", game);
	}
	free_map_passability(game);
}
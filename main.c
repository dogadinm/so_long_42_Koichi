/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:28:31 by mdogadin          #+#    #+#             */
/*   Updated: 2024/01/09 14:09:36 by mdogadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void map(t_game *game, int fd)
{
	int i;
	char *c;
	int x;

	i = 0;
	x = game->row + 1;
	game->map = (char **)malloc(sizeof(char *) * x);
	if (!game->map)
		ft_exit("Error\n", game);
	while (i < x)
	{
		c = get_next_line(fd);
		game->map[i] = ft_strtrim(c, "\n");
		i++;
		free(c);
	}

}
static void map_start(t_game *game)
{
	game->player_x = 0;
	game->player_y = 0;
	game->exit = 0;
	game->player = 0;
	game->row = 0;
	game->col = 0;
	game->end_game = 0;
	game->move = 1;
}

void	start_game(t_game *game)
{	
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->col * WIDTH,
			game->row * HIGHT, "So_long");
	texturs(game);
	render_img(game);		
	mlx_key_hook(game->win, move_key, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_expose_hook(game->win, render_img, game);
	mlx_loop(game->mlx);
}

int main(int argc , char **argv)
{
	t_game game;
	int fd;
	int fd_x;
	int fd_y;
	int fd_map;
	
	fd_x = open(argv[1], O_RDONLY);
	fd_y = open(argv[1], O_RDONLY);
	fd_map = open(argv[1], O_RDONLY);
	check_arg(&game, argc, argv);
	map_start(&game);
	game.score = collectible_on_map(&game);
	game.row = size_row(fd_x);
	game.col = size_col(fd_y);
	fd = open(argv[1], O_RDONLY);
	map(&game, fd);
	all_map_checks(&game, fd_map);
	close(fd_x);
	close(fd_y);
	close(fd);
	close(fd_map);
	start_game(&game);
}
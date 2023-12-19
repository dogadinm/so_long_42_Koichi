/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:28:31 by mdogadin          #+#    #+#             */
/*   Updated: 2023/12/19 12:13:11 by mdogadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
static void map_start(t_game *game)
{
	game->player_x = 0;
	game->player_y = 0;
	game->player_on_box = 0;
	game->exit = 0;
	game->player = 0;
	game->row = 0;
	game->col = 0;
	game->end_game = 0;
	game->move = 1;
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
	game.score = collectible_counter(&game);
	game.row = size_row(&game, fd_x);
	game.col = size_col(&game, fd_y);


	
	
	
}
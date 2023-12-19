/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:28:31 by mdogadin          #+#    #+#             */
/*   Updated: 2023/12/19 15:08:09 by mdogadin         ###   ########.fr       */
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
	game.score = collectible_counter(&game); // не сделал
	game.row = size_row(&game, fd_x);
	game.col = size_col(&game, fd_y);
	fd = open(argv[1], O_RDONLY);
	map(&game, fd);


	
	
	
}
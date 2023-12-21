/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:36:57 by mdogadin          #+#    #+#             */
/*   Updated: 2023/12/21 13:33:57 by mdogadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_img(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img.exit);
	if (game->img.collectible)
		mlx_destroy_image(game->mlx, game->img.collectible);
	if (game->img.player)
		mlx_destroy_image(game->mlx, game->img.player);
	if (game->img.floor)
		mlx_destroy_image(game->mlx, game->img.floor);
	if (game->img.wall)
		mlx_destroy_image(game->mlx, game->img.wall);
	if (game->img.on_exit)
		mlx_destroy_image(game->mlx, game->img.on_exit);
	mlx_destroy_display(game->mlx);
	free_map(game);
	free(game->mlx);
	exit(0);
}

void	free_map_arrangement(t_game *game)
{
	int	i;

	i = 0;
	while (game->map_arrangement[i])
	{
		free(game->map_arrangement[i]);
		i++;
	}
	free(game->map_arrangement);
}

void free_map(t_game *game)
{
    int i;
    i = 0;
    while (game->map[i])
    {
        free(game->map[i]);
        i++;
    }
    free(game->map);
}

void ft_exit(char *s, t_game *game)
{
    ft_printf("Error\nSomething is wrong!\n%s\n", s);
    if (game->map[0])
		free_map(game);
	exit(0);
}

void check_arg(t_game *game, int argc, char **argv)
{
    if (argc != 2)
        ft_exit("Error\nInvalid number of argument\n", game);
}
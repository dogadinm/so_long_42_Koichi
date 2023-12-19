/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:36:57 by mdogadin          #+#    #+#             */
/*   Updated: 2023/12/19 12:03:03 by mdogadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
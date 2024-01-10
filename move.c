/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:56:28 by mdogadin          #+#    #+#             */
/*   Updated: 2024/01/09 12:17:06 by mdogadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	valid_move(t_game *game, int col, int row, int pressed_key)
{
	game->temp = '0';
	if (game->map[row][col] == '1')
		return (-1);
	if (game->map[row][col] == 'C')
		game->score--;
	if (game->map[row][col] == 'E' && game->score > 0)
	{
		game->player_on_box = 1;
		game->temp = 'B';
		return (1);
	}
	if (game->map[row][col] == 'E' && game->score == 0)
	{
		game->end_game = 1;
		ft_printf("\n\nYOU WIN 🥳🏆\n\n");
		close_window(game);
	}
	if (pressed_key != W && pressed_key != S && pressed_key != A
		&& pressed_key != D)
		return (-1);
	else
		return (1);
}

static void	moving(t_game *game, int col, int row, int pressed_key)
{
	int	valid;
	int	tcol;
	int	trow;

	tcol = game->player_y;
	trow = game->player_x;
	(void)pressed_key;
	valid = valid_move(game, col, row, pressed_key);
	if (valid != -1)
	{
		game->player_y = col;
		game->player_x = row;
		if (game->temp != 'B')
			game->map[row][col] = 'P';
		else
			game->map[row][col] = 'B';
		if (game->map[trow][tcol] != 'B')
			game->map[trow][tcol] = '0';
		else
			game->map[trow][tcol] = 'E';
		ft_printf("Movements: %d\n", game->move++);
		render_img(game);
	}
}
int	move_key(int keycode, t_game *game)
{
	int	col;
	int	row;

	col = game->player_y;
	row = game->player_x;
	if (keycode == A)
		col--;
	else if (keycode == W)
		row--;
	else if (keycode == S)
		row++;
	else if (keycode == D)
		col++;
	else if (keycode == ESC)
		close_window(game);
	if (game->end_game != 1)
		moving(game, col, row, keycode);
	return (0);
}
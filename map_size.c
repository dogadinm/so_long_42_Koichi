/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:13:18 by mdogadin          #+#    #+#             */
/*   Updated: 2023/12/21 10:23:45 by mdogadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	size_col(t_game *game, int fd_y)
{
	char *c;
	int y;
	int temp;

	(void)game;
	y = ft_strlen(get_next_line(fd_y)) - 1;
	temp = y;
	if (fd_y < 0)
		ft_exit("Error\nThe fd is empty\n", game);
	while (1)
	{
		c = get_next_line(fd_y);
		if (!c)
			break ;
		y = ft_strlen(c) - 1;
		if (temp != y)
			return (-1);
		free(c);
	}
	return (y);
}

int size_row(t_game *game, int fd_x)
{
	char	*c;
	int		x;

	x = 0;
	(void)game;
	while (1)
	{
		c = get_next_line(fd_x);
		if (!c)
			break ;
		x++;
		free(c);
	}
	if (x == 0)
	{	
		ft_printf("Error\nThe file is empty or not exist.");
		exit(0);
	}
	return (x);

}
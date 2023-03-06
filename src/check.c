/* ************************************************************************************** */
/*                                                                                        */
/*                                                                   :::      ::::::::    */
/*   check.c                                                       :+:      :+:    :+:    */
/*                                                               +:+ +:+         +:+      */
/*   By: seozkan <seozkan@student.42kocaeli.com.tr>            +#+  +:+       +#+         */
/*                                                           +#+#+#+#+#+   +#+            */
/*   Created: 0003/02/28 17:11:59 by zkan                         #+#    #+#              */
/*   Updated: 2023/03/05 23:18:53 by seozkan                     ###   ########.tr        */
/*                                                                                        */
/* ************************************************************************************** */

#include "../includes/so_long.h"

void ft_validate_characters(t_game *game)
{
	size_t x;
	size_t y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] != '0' && game->map[y][x] != '1' && game->map[y][x] != 'E' && game->map[y][x] != 'P' && game->map[y][x] != 'C')
				ft_error_message(E_CHARACTER, 1);
			x++;
		}
		y++;
	}
}

void ft_amount_of_characters(t_game *game)
{
	int x;
	int y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				game->c_count++;
			if (game->map[y][x] == 'E')
				game->e_count++;
			if (game->map[y][x] == 'P')
			{
				game->p_count++;
				game->pl_x = y;
				game->pl_y = x;
			}
			x++;
		}
		y++;
	}
	if (game->p_count != 1 || game->e_count != 1 || game->c_count < 1)
		ft_error_message(E_CHARS, 1);
}

void ft_validate_wall(t_game *game)
{
	int x;
	int y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (y == 0 && game->map[y][x] != '1')
				ft_error_message(E_WALLS, 1);
			if (y == game->rows - 1 && game->map[y][x] != '1')
				ft_error_message(E_WALLS, 1);
			if ((x == 0 || x == (game->columns - 1)) && game->map[y][x] != '1')
				ft_error_message(E_WALLS, 1);
			x++;
		}
		y++;
	}
}

void ft_validate_line_length(t_game *game)
{
	int i;
	int y;

	i = ft_strlen(game->map[0]);
	y = 1;
	while (game->map[y])
	{
		if (i != (int)ft_strlen(game->map[y]))
			ft_error_message(E_INVALIDMAP, 1);
		y++;
	}
	game->rows = y;
	game->columns = i;
}

void check_map(t_game *game, char **av)
{
	read_map(av[1], game);
	ft_validate_line_length(game);
	ft_validate_characters(game);
	ft_amount_of_characters(game);
	ft_validate_wall(game);
	ft_validate_path(game);
}

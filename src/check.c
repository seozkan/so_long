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
	size_t y;
	size_t x;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] != '0' && game->map[x][y] != '1' && game->map[x][y] != 'E' && game->map[x][y] != 'P' && game->map[x][y] != 'C')
				ft_error_message(E_CHARACTER, 1);
			y++;
		}
		x++;
	}
}

void ft_amount_of_characters(t_game *game)
{
	int y;
	int x;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == 'C')
				game->c_count++;
			if (game->map[x][y] == 'E')
				game->e_count++;
			if (game->map[x][y] == 'P')
				game->p_count++;
			y++;
		}
		x++;
	}
	if (game->p_count != 1 || game->e_count != 1 || game->c_count < 1)
		ft_error_message(E_CHARS, 1);
}

void ft_validate_wall(t_game *game)
{
	int y;
	int x;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (x == 0 && game->map[x][y] != '1')
				ft_error_message(E_WALLS, 1);
			if (x == game->rows - 1 && game->map[x][y] != '1')
				ft_error_message(E_WALLS, 1);
			if ((y == 0 || y == (game->columns - 1)) && game->map[x][y] != '1')
				ft_error_message(E_WALLS, 1);
			y++;
		}
		x++;
	}
}

void ft_validate_line_length(t_game *game)
{
	int i;
	int x;

	i = ft_strlen(game->map[0]);
	x = 1;
	while (game->map[x])
	{
		if (i != (int)ft_strlen(game->map[x]))
			ft_error_message(E_INVALIDMAP, 1);
		x++;
	}
	game->rows = x;
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

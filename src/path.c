/* ************************************************************************************** */
/*                                                                                        */
/*                                                                   :::      ::::::::    */
/*   path.c                                                        :+:      :+:    :+:    */
/*                                                               +:+ +:+         +:+      */
/*   By: seozkan <seozkan@student.42kocaeli.com.tr>            +#+  +:+       +#+         */
/*                                                           +#+#+#+#+#+   +#+            */
/*   Created: 2023/03/05 23:13:23 by seozkan                      #+#    #+#              */
/*   Updated: 2023/03/05 23:13:23 by seozkan                     ###   ########.tr        */
/*                                                                                        */
/* ************************************************************************************** */

#include "../includes/so_long.h"

void	ft_floodfill(t_game *game, int x, int y, int *count_c)
{
	if (x <= 0 || x >= game->columns || y <= 0 || y >= game->rows
		|| game->map[y][x] == '1' || game->map[y][x] == 'c'
		|| game->map[y][x] == 'o' || game->map[y][x] == 'e'
		|| game->map[y][x] == 'E')
	{
		return ;
	}
	if (game->map[y][x] == 'C')
	{
		(*count_c)--;
		game->map[y][x] = 'c';
	}
	else if (game->map[y][x] == '0')
		game->map[y][x] = 'o';
	ft_floodfill(game, x, (y + 1), count_c);
	ft_floodfill(game, x, (y - 1), count_c);
	ft_floodfill(game, (x + 1), y, count_c);
	ft_floodfill(game, (x - 1), y, count_c);
}

void	ft_restore(t_game *game)
{
	int	x;
	int	y;
	int	rows;
	int	columns;

	y = 0;
	rows = game->rows;
	columns = game->columns;
	while (y < rows)
	{
		x = 0;
		while (x < columns)
		{
			if (game->map[y][x] == 'c')
				game->map[y][x] = 'C';
			else if (game->map[y][x] == 'e')
				game->map[y][x] = 'E';
			else if (game->map[y][x] == 'o')
				game->map[y][x] = '0';
			x++;
		}
		y++;
	}
}

void	ft_validate_path(t_game *game)
{
	int	x;
	int	y;
	int	count_c;

	y = 0;
	count_c = game->c_count;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->columns)
		{
			if (game->map[y][x] == 'P')
			{
				ft_floodfill(game, x, y, &count_c);
				if (count_c != 0)
					ft_error_message(E_PATH, 1);
				ft_restore(game);
				return ;
			}
			x++;
		}
		y++;
	}
}
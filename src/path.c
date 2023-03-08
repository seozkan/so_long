/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:08:58 by seozkan           #+#    #+#             */
/*   Updated: 2023/03/08 16:54:56 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_floodfill(t_game *game, int x, int y)
{
	if (x <= 0 || x >= game->columns || y <= 0 || y >= game->rows
		|| game->map[y][x] == '1' || game->map[y][x] == 'c'
		|| game->map[y][x] == 'o' || game->map[y][x] == 'e'
		|| game->map[y][x] == 'E')
		return ;
	if (game->map[y][x] == 'C')
	{
		game->c_count--;
		game->map[y][x] = 'c';
	}
	else if (game->map[y][x] == '0')
		game->map[y][x] = 'o';
	ft_floodfill(game, x, (y + 1));
	ft_floodfill(game, x, (y - 1));
	ft_floodfill(game, (x + 1), y);
	ft_floodfill(game, (x - 1), y);
}

void	ft_restore(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->columns)
		{
			if (game->map[y][x] == 'c')
			{
				game->map[y][x] = 'C';
				game->c_count++;
			}
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

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->columns)
		{
			if (game->map[y][x] == 'P')
			{
				ft_floodfill(game, x, y);
				if (game->c_count != 0)
					ft_error_message(E_PATH, game);
				ft_restore(game);
				return ;
			}
			x++;
		}
		y++;
	}
}

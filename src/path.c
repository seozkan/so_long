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
/* 
#include "so_long.h"
 */
/* int	ft_count_c(char **map_2d)
{
	int	x;
	int	y;
	int	rows;
	int	columns;
	int	count_c;

	y = 0;
	count_c = 0;
	rows = ft_count_strings(map_2d);
	columns = ft_strlen(map_2d[0]);
	while (y < rows)
	{
		x = 0;
		while (x < columns)
		{
			if (map_2d[y][x] == 'C')
			{
				count_c++;
			}
			x++;
		}
		y++;
	}
	return (count_c);
}

void	ft_floodfill(t_game *game, int x, int y, int *count_c)
{
	if (x <= 0 || x >= game->columns || y <= 0 || y >= game->rows
		|| game->map_2d[y][x] == '1' || game->map_2d[y][x] == 'c'
		|| game->map_2d[y][x] == 'o' || game->map_2d[y][x] == 'e'
		|| game->map_2d[y][x] == 'E')
	{
		if (game->map_2d[y][x] == 'E')
			game->exit_flag = TRUE;
		return ;
	}
	if (game->map_2d[y][x] == 'C')
	{
		(*count_c)--;
		game->map_2d[y][x] = 'c';
	}
	else if (game->map_2d[y][x] == '0')
		game->map_2d[y][x] = 'o';
	ft_floodfill(game, x, (y + 1), count_c);
	ft_floodfill(game, x, (y - 1), count_c);
	ft_floodfill(game, (x + 1), y, count_c);
	ft_floodfill(game, (x - 1), y, count_c);
}

void	ft_restore(char **map_2d)
{
	int	x;
	int	y;
	int	rows;
	int	columns;

	y = 0;
	rows = ft_count_strings(map_2d);
	columns = ft_strlen(map_2d[0]);
	while (y < rows)
	{
		x = 0;
		while (x < columns)
		{
			if (map_2d[y][x] == 'c')
				map_2d[y][x] = 'C';
			else if (map_2d[y][x] == 'e')
				map_2d[y][x] = 'E';
			else if (map_2d[y][x] == 'o')
				map_2d[y][x] = '0';
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
			if (game->map_2d[y][x] == 'P')
			{
				ft_floodfill(game, x, y, &count_c);
				if (count_c != 0)
					ft_error_message(E_PATH, 1);
				ft_restore(game->map_2d);
				if (game->exit_flag == FALSE)
					ft_error_message(E_PATH, 1);
				return ;
			}
			x++;
		}
		y++;
	}
} */
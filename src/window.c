/* ************************************************************************************** */
/*                                                                                        */
/*                                                                   :::      ::::::::    */
/*   window.c                                                      :+:      :+:    :+:    */
/*                                                               +:+ +:+         +:+      */
/*   By: seozkan <seozkan@student.42kocaeli.com.tr>            +#+  +:+       +#+         */
/*                                                           +#+#+#+#+#+   +#+            */
/*   Created: 2023/03/06 15:03:53 by seozkan                      #+#    #+#              */
/*   Updated: 2023/03/06 15:03:53 by seozkan                     ###   ########.tr        */
/*                                                                                        */
/* ************************************************************************************** */

#include "../includes/so_long.h"

void	ft_fill_floor(t_game *game)
{
	int y;
	int x;

	y = 0;
	while (y < (game->columns))
	{
		x = 0;
		while (x < game->rows)
		{
			game->file = mlx_xpm_file_to_image(game->mlx,
					"./assets/floor.xpm", &game->pxl, &game->pxl);
			mlx_put_image_to_window (game->mlx, game->mlx_win,
				game->file, game->pxl * y * 1,
				game->pxl * x * 1);
			x++;
		}
		y++;
	}
}

void	ft_fill_window(t_game *game)
{
    int y;
    int x;

	ft_fill_floor(game);
    y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->columns)
		{
			if (game->map[y][x] == '1')
				ft_put_limits(game,y,x);
			if (game->map[y][x] == 'C')
				ft_put_collect(game,y,x);
			if (game->map[y][x] == 'P')
				ft_put_player(game);
			if (game->map[y][x] == 'E')
				ft_put_exit(game,y,x);
			x++;
		}
		y++;
	}
}
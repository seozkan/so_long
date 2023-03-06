/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:18:37 by seozkan           #+#    #+#             */
/*   Updated: 2023/03/06 23:52:39 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_window(t_game *game)
{
	game->pxl = 50;
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, game->pxl * game->columns,
			game->pxl * game->rows, "42 SoLong by seozkan");
	if (!game->mlx)
		exit(EXIT_FAILURE);
	ft_fill_window(game);
}

int	ft_close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(1);
	return (0);
}

void	ft_fill_floor(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < (game->columns))
	{
		x = 0;
		while (x < game->rows)
		{
			game->limits = mlx_xpm_file_to_image(game->mlx,
					"./assets/floor.xpm", &game->pxl, &game->pxl);
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->limits,
				game->pxl * y * 1, game->pxl * x * 1);
			x++;
		}
		y++;
	}
}

void	ft_fill_window(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->columns)
		{
			if (game->map[y][x] == '1')
				ft_put_limits(game, y, x);
			if (game->map[y][x] == 'C')
				ft_put_collect(game, y, x);
			if (game->map[y][x] == 'P')
				ft_put_player(game);
			if (game->map[y][x] == 'E')
				ft_put_exit(game, y, x);
			x++;
		}
		y++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:18:37 by seozkan           #+#    #+#             */
/*   Updated: 2023/03/11 13:35:42 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_window(t_game *game)
{
	game->pxl = 50;
	game->mlx = mlx_init();
	if (!game->mlx)
		exit(EXIT_FAILURE);
	game->mlx_win = mlx_new_window(game->mlx, game->pxl * game->columns,
			game->pxl * game->rows, "42 SoLong by seozkan");
	init_assets(game);
	mlx_loop_hook(game->mlx, &ft_draw_map, game);
	mlx_hook(game->mlx_win, 2, 1L << 0, ft_keyboard, game);
	mlx_hook(game->mlx_win, 17, 1L << 5, ft_close_window, game);
	mlx_loop(game->mlx);
}

int	ft_close_window(t_game *game)
{
	ft_free_map_2d(game->map);
	close_img(game);
	mlx_destroy_window(game->mlx, game->mlx_win);
	free(game->mlx);
	free(game);
	exit(1);
	return (0);
}

int	ft_draw_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->columns)
		{
			if (game->map[y][x] == '0')
				ft_put_floor(game, x, y);
			if (game->map[y][x] == '1')
				ft_put_limits(game, x, y);
			if (game->map[y][x] == 'C')
				ft_put_collect(game, x, y);
			if (game->map[y][x] == 'P')
				ft_put_player(game);
			if (game->map[y][x] == 'E')
				ft_put_exit(game, x, y);
			x++;
		}
		y++;
	}
	return (1);
}

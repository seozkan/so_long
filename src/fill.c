/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:50:50 by seozkan           #+#    #+#             */
/*   Updated: 2023/03/06 23:56:05 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_put_limits(t_game *game, int x, int y)
{
	game->limits = mlx_xpm_file_to_image(game->mlx, "./assets/tree.xpm",
			&game->pxl, &game->pxl);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->limits,
		game->pxl * y, game->pxl * x);
}

void	ft_put_floor(t_game *game, int x, int y)
{
	game->floor = mlx_xpm_file_to_image(game->mlx,
			"./assets/floor.xpm", &game->pxl, &game->pxl);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor,
		game->pxl * y, game->pxl * x);
}

void	ft_put_collect(t_game *game, int x, int y)
{
	game->collect = mlx_xpm_file_to_image(game->mlx, "./assets/pokeball.xpm",
			&game->pxl, &game->pxl);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->collect,
		game->pxl * y, game->pxl * x);
}

void	ft_put_player(t_game *game)
{
	game->player = mlx_xpm_file_to_image(game->mlx, "./assets/down.xpm",
			&game->pxl, &game->pxl);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->player, game->pxl
		* game->x, game->pxl * game->y);
}

void	ft_put_exit(t_game *game, int x, int y)
{
	if (game->c_count == 0)
		game->exit = mlx_xpm_file_to_image(game->mlx,
				"./assets/exit_open.xpm", &game->pxl, &game->pxl);
	else
		game->exit = mlx_xpm_file_to_image(game->mlx,
				"./assets/exit_closed.xpm", &game->pxl, &game->pxl);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->exit, game->pxl * y,
		game->pxl * x);
}

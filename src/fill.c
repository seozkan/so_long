/* ************************************************************************************** */
/*                                                                                        */
/*                                                                   :::      ::::::::    */
/*   fill.c                                                        :+:      :+:    :+:    */
/*                                                               +:+ +:+         +:+      */
/*   By: seozkan <seozkan@student.42kocaeli.com.tr>            +#+  +:+       +#+         */
/*                                                           +#+#+#+#+#+   +#+            */
/*   Created: 2023/03/06 15:11:41 by seozkan                      #+#    #+#              */
/*   Updated: 2023/03/06 15:11:41 by seozkan                     ###   ########.tr        */
/*                                                                                        */
/* ************************************************************************************** */

#include "../includes/so_long.h"

void	ft_put_limits(t_game *game,int x,int y)
{
	game->file = mlx_xpm_file_to_image(game->mlx,
			"./assets/tree.xpm", &game->pxl, &game->pxl);
	mlx_put_image_to_window (game->mlx, game->mlx_win,
		game->file, game->pxl * y,
		game->pxl * x);
}

void	ft_put_floor(t_game *game,int x,int y)
{
	game->file = mlx_xpm_file_to_image(game->mlx,
			"./assets/floor.xpm", &game->pxl, &game->pxl);
	mlx_put_image_to_window (game->mlx, game->mlx_win,
		game->file, game->pxl * y,
		game->pxl * x);
}

void	ft_put_collect(t_game *game,int x,int y)
{
	game->file = mlx_xpm_file_to_image(game->mlx,
			"./assets/pokeball.xpm", &game->pxl, &game->pxl);
	mlx_put_image_to_window (game->mlx, game->mlx_win,
		game->file, game->pxl * y,
		game->pxl * x);
}

void	ft_put_player(t_game *game)
{
	game->file = mlx_xpm_file_to_image(game->mlx,"./assets/enemy.xpm", &game->pxl, &game->pxl);
	mlx_put_image_to_window (game->mlx, game->mlx_win,
		game->file, game->pxl * game->pl_y,
		game->pxl * game->pl_x);
}

void	ft_put_exit(t_game *game,int x,int y)
{
	if (game->c_count == 0)
		game->file = mlx_xpm_file_to_image(game->mlx,
				"./assets/exit_open.xpm", &game->pxl, &game->pxl);
	else
		game->file = mlx_xpm_file_to_image(game->mlx,
				"./assets/exit_closed.xpm", &game->pxl, &game->pxl);
	mlx_put_image_to_window (game->mlx, game->mlx_win,
		game->file, game->pxl * y,
		game->pxl * x);
}
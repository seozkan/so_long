/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_two_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:55:53 by seozkan           #+#    #+#             */
/*   Updated: 2023/03/09 13:25:45 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_put_enemy(t_game *game, int x, int y)
{
	if (game->enemy)
		mlx_destroy_image(game->mlx, game->enemy);
	game->enemy = mlx_xpm_file_to_image(game->mlx, "./assets/enemy.xpm",
			&game->pxl, &game->pxl);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->enemy, game->pxl
		* x, game->pxl * y);
}

void	ft_put_blank(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->blank, game->pxl
		* x, game->pxl * y);
}

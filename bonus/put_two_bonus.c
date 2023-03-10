/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_two_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:55:53 by seozkan           #+#    #+#             */
/*   Updated: 2023/03/10 19:06:42 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	ft_put_bomb(t_game *game, int x, int y)
{
	if (game->bomb)
		mlx_destroy_image(game->mlx, game->bomb);
	game->bomb = mlx_xpm_file_to_image(game->mlx, "./assets/bomb.xpm",
			&game->pxl, &game->pxl);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->bomb, game->pxl
		* x, game->pxl * y);
}

void	ft_put_blank(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->blank, game->pxl
		* x, game->pxl * y);
}

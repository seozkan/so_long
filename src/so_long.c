/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:13:35 by seozkan           #+#    #+#             */
/*   Updated: 2023/03/08 17:05:46 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	close_img(t_game *game)
{
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->limits)
		mlx_destroy_image(game->mlx, game->limits);
	if (game->collect)
		mlx_destroy_image(game->mlx, game->collect);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
}

void	init_data(t_game *game)
{
	game->map = NULL;
	game->c_count = 0;
	game->e_count = 0;
	game->p_count = 0;
	game->mov = 0;
	game->floor = NULL;
	game->limits = NULL;
	game->player = NULL;
	game->collect = NULL;
	game->exit = NULL;
}

int	main(int ac, char **av)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (0);
	init_data(game);
	if (ac != 2)
		ft_error_message(E_ARG, game);
	read_map(av[1], game);
	check_map(game);
	ft_window(game);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:59:06 by seozkan           #+#    #+#             */
/*   Updated: 2023/03/08 17:02:31 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_move_up(t_game *game)
{
	game->map[game->y][game->x] = '0';
	if (game->map[game->y - 1][game->x] == 'C')
		game->c_count--;
	game->map[game->y - 1][game->x] = 'P';
	game->y--;
	game->mov++;
	ft_printf("Mov: %d\n", game->mov);
	ft_fill_window(game);
}

void	ft_move_down(t_game *game)
{
	game->map[game->y][game->x] = '0';
	if (game->map[game->y + 1][game->x] == 'C')
		game->c_count--;
	game->map[game->y + 1][game->x] = 'P';
	game->y++;
	game->mov++;
	ft_printf("Mov: %d\n", game->mov);
	ft_fill_window(game);
}

void	ft_move_left(t_game *game)
{
	game->map[game->y][game->x] = '0';
	if (game->map[game->y][game->x - 1] == 'C')
		game->c_count--;
	game->map[game->y][game->x - 1] = 'P';
	game->x--;
	game->mov++;
	ft_printf("Mov: %d\n", game->mov);
	ft_fill_window(game);
}

void	ft_move_right(t_game *game)
{
	game->map[game->y][game->x] = '0';
	if (game->map[game->y][game->x + 1] == 'C')
		game->c_count--;
	game->map[game->y][game->x + 1] = 'P';
	game->x++;
	game->mov++;
	ft_printf("Mov: %d\n", game->mov);
	ft_fill_window(game);
}

int	ft_keyboard(int keyhook, t_game *game)
{
	if (keyhook == K_ESC)
		ft_close_window(game);
	if (game->c_count == 0 && ((keyhook == K_RIGHT && game->map[game->y][game->x
				+ 1] == 'E') || (keyhook == K_DOWN && game->map[game->y
				+ 1][game->x] == 'E') || (keyhook == K_LEFT
				&& game->map[game->y][game->x - 1] == 'E') || (keyhook == K_UP
				&& game->map[game->y - 1][game->x] == 'E')))
	{
		ft_printf("You Win!\n");
		ft_close_window(game);
	}
	if (keyhook == K_UP && game->map[game->y - 1][game->x] != '1'
		&& game->map[game->y - 1][game->x] != 'E')
		ft_move_up(game);
	if (keyhook == K_LEFT && game->map[game->y][game->x - 1] != '1'
		&& game->map[game->y][game->x - 1] != 'E')
		ft_move_left(game);
	if (keyhook == K_DOWN && game->map[game->y + 1][game->x] != '1'
		&& game->map[game->y + 1][game->x] != 'E')
		ft_move_down(game);
	if (keyhook == K_RIGHT && game->map[game->y][game->x + 1] != '1'
		&& game->map[game->y][game->x + 1] != 'E')
		ft_move_right(game);
	return (0);
}

/* ************************************************************************************** */
/*                                                                                        */
/*                                                                   :::      ::::::::    */
/*   so_long.c                                                     :+:      :+:    :+:    */
/*                                                               +:+ +:+         +:+      */
/*   By: seozkan <seozkan@student.42kocaeli.com.tr>            +#+  +:+       +#+         */
/*                                                           +#+#+#+#+#+   +#+            */
/*   Created: 0003/03/01 15:07:53 by zkan                         #+#    #+#              */
/*   Updated: 2023/03/05 23:16:55 by seozkan                     ###   ########.tr        */
/*                                                                                        */
/* ************************************************************************************** */

#include "../includes/so_long.h"

void init_data(t_game *game)
{
	game->c_count = 0;
	game->e_count = 0;
	game->p_count = 0;
}

int	main(int ac, char **av)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (0);
	if (ac != 2)
		ft_error_message(E_ARG,1);
	check_map(game, av);
	return (0);
}

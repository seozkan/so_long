/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:13:49 by seozkan           #+#    #+#             */
/*   Updated: 2023/03/11 13:46:06 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/ft_printf/ft_printf.h"
# include "../lib/libft/libft.h"
# include "../lib/mlx/mlx.h"
# include <fcntl.h>

# define K_ESC 53
# define K_UP 13
# define K_DOWN 1
# define K_LEFT 0
# define K_RIGHT 2

# define E_MALLOC "Failed to allocate memory!"
# define E_ARG "The program must be run with a map argument!"
# define E_FILE "The file could not be opened!"
# define E_CHARACTER "The map contains at least one invalid character!"
# define E_CHARS "The map does not contain the required characters!"
# define E_INVALIDMAP "The map must be rectangular!"
# define E_WALLS "The map must be surrounded by walls!"
# define E_PATH "The map path must be valid!"
# define E_FORMAT "The file type must be .ber!"
# define E_EMPTYFILE "The file is empty!"
# define E_IMAGE "There is something wrong with the image you want to put."

typedef struct s_game
{
	char	**map;
	int		c_count;
	int		e_count;
	int		p_count;
	int		rows;
	int		columns;
	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;
	int		mov;
	int		pxl;
	void	*limits;
	void	*floor;
	void	*collect;
	void	*player;
	void	*exit;

}			t_game;

void		check_map(t_game *game);
void		ft_validate_chars(t_game *game);
void		ft_validate_amount_chars(t_game *game);
void		ft_validate_wall(t_game *game);
void		ft_validate_rectangle(t_game *game);

void		ft_put_limits(t_game *game, int x, int y);
void		ft_put_floor(t_game *game, int x, int y);
void		ft_put_collect(t_game *game, int x, int y);
void		ft_put_player(t_game *game);
void		ft_put_exit(t_game *game, int x, int y);

void		ft_move_up(t_game *game);
void		ft_move_down(t_game *game);
void		ft_move_left(t_game *game);
void		ft_move_right(t_game *game);
int			ft_keyboard(int keyhook, t_game *game);

void		ft_floodfill(t_game *game, int x, int y);
void		ft_restore(t_game *game);
void		ft_validate_path(t_game *game);

void		close_img(t_game *game);
void		init_data(t_game *game);

void		ft_validate_file(char *map_path, t_game *game);
void		read_map(char *map_path, t_game *game);
void		ft_error_message(char *str, t_game *game);
void		ft_free_map_2d(char **map);

void		ft_window(t_game *game);
int			ft_close_window(t_game *game);
int			ft_draw_map(t_game *game);
void		init_assets(t_game *game);
#endif
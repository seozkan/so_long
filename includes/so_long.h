/* ************************************************************************************** */
/*                                                                                        */
/*                                                                   :::      ::::::::    */
/*   so_long.h                                                     :+:      :+:    :+:    */
/*                                                               +:+ +:+         +:+      */
/*   By: seozkan <seozkan@student.42kocaeli.com.tr>            +#+  +:+       +#+         */
/*                                                           +#+#+#+#+#+   +#+            */
/*   Created: 0003/03/01 19:46:09 by zkan                         #+#    #+#              */
/*   Updated: 2023/03/05 23:16:35 by seozkan                     ###   ########.tr        */
/*                                                                                        */
/* ************************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../lib/ft_printf/ft_printf.h"
#include "../lib/libft/libft.h"
#include "../lib/mlx/mlx.h"
#include <fcntl.h>

# define K_ESC 65307
# define K_UP 65362
# define K_DOWN 65364
# define K_LEFT 65361
# define K_RIGHT 65363
# define K_A			97
# define K_W			119
# define K_S			115
# define K_D			100

#define E_MALLOC "Error with malloc."
#define E_ARG "Please give me one map"
#define E_FILE "I cannot open the file, sorry!"
#define E_CHARACTER "The map contains at least one invalid character"
#define E_CHARS "The map does not contain the required characters"
#define E_INVALIDMAP "Give me a valid map. I wanna rectangles!"
#define E_WALLS "This map is not surrounded by walls! Gimme a fortress!"
#define E_PATH "Hey,that path is not valid! I cannot jump walls."
#define E_FORMAT "Format not allowed."
#define E_EMPTYFILE "Yo! Nothing to read here."
#define E_IMAGE "There is something wrong with the image you want to put."
#define E_MAX "You're kind of exagerating here."

typedef struct s_game
{
	char **map;
	int c_count;
	int e_count;
	int p_count;
	int rows;
	int columns;
	void *mlx;
	void *mlx_win;
	int x;
	int y;
	int mov;
	int pxl;
	char *limits;
	char *floor;
	char *collect;
	char *player;
	char *exit;

} t_game;

void ft_validate_characters(t_game *game);
void ft_amount_of_characters(t_game *game);
void ft_validate_line_length(t_game *game);
void check_map(t_game *game, char **av);

void ft_error_message(char *str, int error);
void ft_validate_file(char *map_path);
void read_map(char *map_path, t_game *game);

void ft_floodfill(t_game *game, int x, int y);
void ft_restore(t_game *game);
void ft_validate_path(t_game *game);
void	ft_fill_window(t_game *game);

void	ft_put_limits(t_game *game,int x,int y);
void	ft_put_floor(t_game *game,int x,int y);
void	ft_put_collect(t_game *game,int x,int y);
void	ft_put_player(t_game *game);
void	ft_put_exit(t_game *game,int x,int y);

void	ft_move_up(t_game *game);
void	ft_move_down(t_game *game);
void	ft_move_left(t_game *game);
void	ft_move_right(t_game *game);

int	ft_keyboard(int keyhook, t_game *game);
int	ft_close_window(t_game *game);
void	ft_window(t_game *game);
#endif
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
#include <fcntl.h>

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
	int exit_flag;
} t_game;

void ft_validate_characters(t_game *game);
void ft_amount_of_characters(t_game *game);
void ft_validate_line_length(t_game *game);
void check_map(t_game *game, char **av);

void ft_error_message(char *str, int error);
void init_data(t_game *game);
void ft_validate_file(char *map_path);
void read_map(char *map_path,t_game *game);

void	ft_floodfill(t_game *game, int x, int y, int *count_c);
void	ft_restore(t_game *game);
void	ft_validate_path(t_game *game);

#endif
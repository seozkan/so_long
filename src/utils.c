/* ************************************************************************************** */
/*                                                                                        */
/*                                                                   :::      ::::::::    */
/*   utils.c                                                       :+:      :+:    :+:    */
/*                                                               +:+ +:+         +:+      */
/*   By: seozkan <seozkan@student.42kocaeli.com.tr>            +#+  +:+       +#+         */
/*                                                           +#+#+#+#+#+   +#+            */
/*   Created: 0003/02/28 16:48:59 by zkan                         #+#    #+#              */
/*   Updated: 2023/03/05 23:17:08 by seozkan                     ###   ########.tr        */
/*                                                                                        */
/* ************************************************************************************** */

#include "../includes/so_long.h"

void	ft_validate_file(char *map_path)
{
	int	i;

	i = ft_strlen(map_path) - 1;
	if (map_path[i] != 'r')
		ft_error_message(E_FORMAT, 1);
	i--;
	if (map_path[i] != 'e')
		ft_error_message(E_FORMAT, 1);
	i--;
	if (map_path[i] != 'b')
		ft_error_message(E_FORMAT, 1);
	i--;
	if (map_path[i] != '.')
		ft_error_message(E_FORMAT, 1);
}

void	read_map(char *map_path,t_game *game)
{
	char	*str_map;
	int		fd;
	char	c;
	int		count;

	count = 0;
	ft_validate_file(map_path);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		ft_error_message(E_FILE, 1);
	while (read(fd, &c, 1) == 1)
		count++;
	if (count == 0)
		ft_error_message(E_EMPTYFILE, 1);
	str_map = (char *)malloc(sizeof(char) * (count + 1));
	if (!str_map)
		ft_error_message(E_MALLOC, 1);
	close(fd);
	fd = open(map_path, O_RDONLY);
	read(fd, str_map, count);
	str_map[count] = '\0';
	close(fd);
	game->map = ft_split(str_map,'\n');
}
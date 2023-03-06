/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:26:01 by seozkan           #+#    #+#             */
/*   Updated: 2023/03/06 22:50:30 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error_message(char *str, int error)
{
	if (!str)
		ft_printf("Error: ./so_long");
	else
		ft_printf("Error!\n%s\n", str);
	(void)error;
	exit(error);
}

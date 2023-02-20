/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_play.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:48:36 by samartin          #+#    #+#             */
/*   Updated: 2023/02/20 13:59:33 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		render_frame(t_game *sl_game)
{
	
	int x = 0;
	int y = 0;
	
	while (sl_game->map[y])
	
	{
		x = 0;
		while(sl_game->map[y][x])
		{
			ft_printf("%c", sl_game->map[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
	}
	return (1);
}

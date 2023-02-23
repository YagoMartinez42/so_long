/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_play.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:48:36 by samartin          #+#    #+#             */
/*   Updated: 2023/02/23 14:07:14 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int sl_load_xpms(t_game *sl_game)
{
	sl_game->char_spr.img = mlx_xpm_file_to_image(sl_game->grph.mlx, CHAR_FILE,
			&(sl_game->char_spr.wd), &(sl_game->char_spr.ht));
	sl_game->coin_spr.img = mlx_xpm_file_to_image(sl_game->grph.mlx, COIN_FILE,
			&(sl_game->coin_spr.wd), &(sl_game->coin_spr.ht));
	sl_game->empty_spr.img = mlx_xpm_file_to_image(sl_game->grph.mlx, EMPTY_FILE,
			&(sl_game->empty_spr.wd), &(sl_game->empty_spr.ht));
	sl_game->exit_spr.img = mlx_xpm_file_to_image(sl_game->grph.mlx, EXIT_FILE,
			&(sl_game->exit_spr.wd), &(sl_game->exit_spr.ht));
	sl_game->wall_spr.img = mlx_xpm_file_to_image(sl_game->grph.mlx, WALL_FILE,
			&(sl_game->wall_spr.wd), &(sl_game->wall_spr.ht));
	return (1);
}


int	render_frame(t_game *sl_game)
{
	int	x = 0;
	int	y = 0;

	while (sl_game->map[y])
	{
		x = 0;
		while (sl_game->map[y][x])
		{
			if (sl_game->map[y][x] == 'P')
				mlx_put_image_to_window(sl_game->grph.mlx, sl_game->grph.win,
						sl_game->char_spr.img, (x * SPR_SIZE), (y * SPR_SIZE));
			else if (sl_game->map[y][x] == 'E')
				mlx_put_image_to_window(sl_game->grph.mlx, sl_game->grph.win,
						sl_game->exit_spr.img, (x * SPR_SIZE), (y * SPR_SIZE));
			else if (sl_game->map[y][x] == 'C')
				mlx_put_image_to_window(sl_game->grph.mlx, sl_game->grph.win,
						sl_game->coin_spr.img, (x * SPR_SIZE), (y * SPR_SIZE));
			else if (sl_game->map[y][x] == '1')
				mlx_put_image_to_window(sl_game->grph.mlx, sl_game->grph.win,
						sl_game->wall_spr.img, (x * SPR_SIZE), (y * SPR_SIZE));
			else
				mlx_put_image_to_window(sl_game->grph.mlx, sl_game->grph.win,
						sl_game->empty_spr.img, (x * SPR_SIZE), (y * SPR_SIZE));
			x++;
		}
		ft_printf("\n");
		y++;
	}
	return (1);
}

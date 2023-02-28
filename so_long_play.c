/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_play.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:48:36 by samartin          #+#    #+#             */
/*   Updated: 2023/02/28 16:01:02 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_load_xpms(t_game *sl_game)
{
	sl_game->char_spr.img = mlx_xpm_file_to_image(sl_game->grph.mlx, \
			CHAR_FILE, &(sl_game->char_spr.wd), &(sl_game->char_spr.ht));
	sl_game->coin_spr.img = mlx_xpm_file_to_image(sl_game->grph.mlx, \
			COIN_FILE, &(sl_game->coin_spr.wd), &(sl_game->coin_spr.ht));
	sl_game->empty_spr.img = mlx_xpm_file_to_image(sl_game->grph.mlx, \
			EMPTY_FILE, &(sl_game->empty_spr.wd), &(sl_game->empty_spr.ht));
	sl_game->exit_spr.img = mlx_xpm_file_to_image(sl_game->grph.mlx, \
			EXIT_FILE, &(sl_game->exit_spr.wd), &(sl_game->exit_spr.ht));
	sl_game->wall_spr.img = mlx_xpm_file_to_image(sl_game->grph.mlx, \
			WALL_FILE, &(sl_game->wall_spr.wd), &(sl_game->wall_spr.ht));
	return (1);
}

void	sl_put_imgs(t_game *sl_game, t_vec2 xy)
{
	if (sl_game->map[xy.y][xy.x] == 'E' && sl_game->coins <= 0)
		mlx_put_image_to_window(sl_game->grph.mlx, sl_game->grph.win, \
			sl_game->exit_spr.img, (xy.x * SPR_SIZE), (xy.y * SPR_SIZE));
	else if (sl_game->map[xy.y][xy.x] == 'C')
		mlx_put_image_to_window(sl_game->grph.mlx, sl_game->grph.win, \
			sl_game->coin_spr.img, (xy.x * SPR_SIZE), (xy.y * SPR_SIZE));
	else if (sl_game->map[xy.y][xy.x] == '1')
		mlx_put_image_to_window(sl_game->grph.mlx, sl_game->grph.win, \
			sl_game->wall_spr.img, (xy.x * SPR_SIZE), (xy.y * SPR_SIZE));
	else
		mlx_put_image_to_window(sl_game->grph.mlx, sl_game->grph.win, \
			sl_game->empty_spr.img, (xy.x * SPR_SIZE), (xy.y * SPR_SIZE));
	mlx_put_image_to_window(sl_game->grph.mlx, sl_game->grph.win, \
			sl_game->char_spr.img, (sl_game->char_pos.x * SPR_SIZE), \
			(sl_game->char_pos.y * SPR_SIZE));
	
}

void	sl_displace_player(t_game *sl_game, char dis_dir)
{
	t_vec2	dest;

	dest = sl_game->char_pos;
	if (dis_dir == 'U')
		dest.y--;
	else if (dis_dir == 'D')
		dest.y++;
	else if (dis_dir == 'L')
		dest.x--;
	else if (dis_dir == 'R')
		dest.x++;
	if (sl_game->map[dest.y][dest.x] != '1')
	{
		sl_check_conditions(sl_game, dest);
		if (sl_game->map[dest.y][dest.x] == 'C')
			sl_game->map[dest.y][dest.x] = '0';
		sl_game->char_pos = dest;
		sl_game->moves++;
	}
}

void	sl_check_conditions(t_game *sl_game, t_vec2 pos)
{
	if (sl_game->map[pos.y][pos.x] == 'C')
		sl_game->coins--;
	ft_printf("Coins: %i\n", sl_game->coins);
	ft_printf("Movements: %i\n", sl_game->moves);
	if (sl_game->map[pos.y][pos.x] == 'E' && !sl_game->coins)
	{
		ft_printf("Completed!\n");
		exit(1);
	}
}

int	render_frame(t_game *sl_game)
{
	t_vec2	xy;

	xy.y = 0;
	while (sl_game->map[xy.y])
	{
		xy.x = 0;
		while (sl_game->map[xy.y][xy.x])
		{
			sl_put_imgs(sl_game, xy);
			xy.x++;
		}
		xy.y++;
	}
	return (1);
}

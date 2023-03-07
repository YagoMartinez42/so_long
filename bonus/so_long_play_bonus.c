/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_play_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:48:36 by samartin          #+#    #+#             */
/*   Updated: 2023/03/07 11:19:49 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	sl_put_player(t_game *sl_game)
{
	size_t	step;

	step = (((sl_game->char_step % 3) + 1) * sl_game->char_dir) - 1;
	mlx_put_image_to_window(sl_game->grph.mlx, sl_game->grph.win, \
			sl_game->char_spr[step].img, (sl_game->char_pos.x), \
			(sl_game->char_pos.y));
	if (sl_game->key_on == 0)
	{
		sl_game->char_step++;
		if (sl_game->char_dir == 1)
			sl_game->char_pos.y -= (SPR_SIZE / 8);
		else if (sl_game->char_dir == 2)
			sl_game->char_pos.y += (SPR_SIZE / 8);
		else if (sl_game->char_dir == 3)
			sl_game->char_pos.x -= (SPR_SIZE / 8);
		else
			sl_game->char_pos.x -= (SPR_SIZE / 8);
		if (sl_game->char_step >= 8)
		{
			sl_game->key_on = 1;
			sl_game->char_step = 0;
		}
	}
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
	sl_put_player(sl_game);
}

void	sl_displace_player(t_game *sl_game, size_t dis_dir)
{
	t_vec2	dest;

	sl_game->key_on = 0;
	sl_game->char_dir = dis_dir;
	dest.x = sl_game->char_pos.x / SPR_SIZE;
	dest.y = sl_game->char_pos.y / SPR_SIZE;
	if (dis_dir == 1)
		dest.y--;
	else if (dis_dir == 2)
		dest.y++;
	else if (dis_dir == 3)
		dest.x--;
	else if (dis_dir == 4)
		dest.x++;
	if (sl_game->map[dest.y][dest.x] != '1')
	{
		sl_game->moves++;
		sl_check_conditions(sl_game, dest);
	}
}

void	sl_check_conditions(t_game *sl_game, t_vec2 pos)
{
	if (sl_game->map[pos.y][pos.x] == 'C')
	{
		sl_game->coins--;
		sl_game->map[pos.y][pos.x] = '0';
	}
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_play_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:48:36 by samartin          #+#    #+#             */
/*   Updated: 2023/03/10 14:10:23 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	sl_put_player(t_game *sl_game)
{
	size_t	spr_idx;
	size_t	step_x;
	size_t	step_y;
	clock_t	elapsed;

	step_x = 0;
	step_y = 0;
	if (sl_game->key_on == 0)
	{
		if (sl_game->char_dir == 0)
			step_y = (ANIM_ST - sl_game->char_step) * (SPR_SZ / ANIM_ST);
		else if (sl_game->char_dir == 1)
			step_x = (ANIM_ST - sl_game->char_step) * (SPR_SZ / ANIM_ST);
		else if (sl_game->char_dir == 2)
			step_y = -1 * ((ANIM_ST - sl_game->char_step) * (SPR_SZ / ANIM_ST));
		else if (sl_game->char_dir == 3)
			step_x = -1 * ((ANIM_ST - sl_game->char_step) * (SPR_SZ / ANIM_ST));
	}
	spr_idx = ((ANIM_ST / 2) * sl_game->char_dir) \
			+ (sl_game->char_step % (CHR_SPR_CNT / 4));
	mlx_put_image_to_window(sl_game->grph.mlx, sl_game->grph.win, \
			sl_game->char_spr[spr_idx].img, (sl_game->char_pos.x * SPR_SZ) \
			+ step_x, (sl_game->char_pos.y * SPR_SZ) + step_y);
	if (sl_game->key_on == 0)
	{
		elapsed = clock() - sl_game->anim_start;
		if (elapsed > CLOCKS_PER_SEC / 20)
		{
			sl_game->char_step++;
			sl_game->anim_start = clock();
		}
		if (sl_game->char_step >= ANIM_ST)
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
			sl_game->exit_spr.img, (xy.x * SPR_SZ), (xy.y * SPR_SZ));
	else if (sl_game->map[xy.y][xy.x] == 'C')
		mlx_put_image_to_window(sl_game->grph.mlx, sl_game->grph.win, \
			sl_game->coin_spr.img, (xy.x * SPR_SZ), (xy.y * SPR_SZ));
	else if (sl_game->map[xy.y][xy.x] == '1')
		mlx_put_image_to_window(sl_game->grph.mlx, sl_game->grph.win, \
			sl_game->wall_spr.img, (xy.x * SPR_SZ), (xy.y * SPR_SZ));
	else
		mlx_put_image_to_window(sl_game->grph.mlx, sl_game->grph.win, \
			sl_game->empty_spr.img, (xy.x * SPR_SZ), (xy.y * SPR_SZ));
}

void	sl_displace_player(t_game *sl_game, size_t dis_dir)
{
	t_vec2	dest;

	sl_game->char_dir = dis_dir;
	dest.x = sl_game->char_pos.x;
	dest.y = sl_game->char_pos.y;
	if (dis_dir == 0)
		dest.y--;
	else if (dis_dir == 1)
		dest.x--;
	else if (dis_dir == 2)
		dest.y++;
	else if (dis_dir == 3)
		dest.x++;
	if (sl_game->map[dest.y][dest.x] != '1')
	{
		sl_game->key_on = 0;
		sl_game->anim_start = clock();
		sl_game->moves++;
		sl_check_conditions(sl_game, dest);
		sl_game->char_pos = dest;
	}
}

void	sl_check_conditions(t_game *sl_game, t_vec2 pos)
{
	if (sl_game->map[pos.y][pos.x] == 'C')
	{
		sl_game->coins--;
		sl_game->map[pos.y][pos.x] = '0';
	}
	if (sl_game->map[pos.y][pos.x] == 'E' && !sl_game->coins)
	{
		ft_printf("Completed!\n");
		exit(1);
	}
}

int	render_frame(t_game *sl_game)
{
	t_vec2	xy;
	char	moves[12];
	char	*num;

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
	sl_put_player(sl_game);
	ft_strcpy(moves, "Moves: ");
	ft_strcat(moves, num = ft_itoa((int)sl_game->moves));
	mlx_string_put(sl_game->grph.mlx, sl_game->grph.win, \
			8, 16, 0x880088, moves);
	free (num);
	return (1);
}

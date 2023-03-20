/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_animations_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:04:13 by samartin          #+#    #+#             */
/*   Updated: 2023/03/20 15:49:34 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_vec2	sl_get_step(t_game *sl_game)
{
	t_vec2	step;

	step.x = 0;
	step.y = 0;
	if (sl_game->key_on == 0)
	{
		if (sl_game->char_dir == 0)
			step.y = (ANIM_ST - sl_game->char_step) * (SPR_SZ / ANIM_ST);
		else if (sl_game->char_dir == 1)
			step.x = (ANIM_ST - sl_game->char_step) * (SPR_SZ / ANIM_ST);
		else if (sl_game->char_dir == 2)
			step.y = -1 * ((ANIM_ST - sl_game->char_step) * (SPR_SZ / ANIM_ST));
		else if (sl_game->char_dir == 3)
			step.x = -1 * ((ANIM_ST - sl_game->char_step) * (SPR_SZ / ANIM_ST));
	}
	return (step);
}

void	sl_chrono(t_game *sl_game)
{
	clock_t	elapsed;

	if (sl_game->key_on == 0)
	{
		elapsed = clock() - sl_game->anim_start;
		if (elapsed > CLOCKS_PER_SEC / 25)
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

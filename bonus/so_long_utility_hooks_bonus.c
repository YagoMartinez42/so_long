/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utility_hooks_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:58:10 by samartin          #+#    #+#             */
/*   Updated: 2023/03/06 16:04:17 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	sl_controls(int keycode, t_game *sl_game)
{
	if (keycode == 53)
		close_window(sl_game);
	else if ((keycode == 13 || keycode == 126) && sl_game->key_on == 1)
		sl_displace_player(sl_game, 1);
	else if ((keycode == 0 || keycode == 123) && sl_game->key_on == 1)
		sl_displace_player(sl_game, 2);
	else if ((keycode == 1 || keycode == 125) && sl_game->key_on == 1)
		sl_displace_player(sl_game, 3);
	else if ((keycode == 2 || keycode == 124) && sl_game->key_on == 1)
		sl_displace_player(sl_game, 4);
	return (keycode);
}

int	close_window(t_game *sl_game)
{
	mlx_destroy_window(sl_game->grph.mlx, sl_game->grph.win);
	sl_clear_all(sl_game);
	exit(0);
	return (0);
}

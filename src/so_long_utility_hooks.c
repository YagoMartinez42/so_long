/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utility_hooks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:58:10 by samartin          #+#    #+#             */
/*   Updated: 2023/03/02 12:03:25 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_controls(int keycode, t_game *sl_game)
{
	if (keycode == 53)
		close_window(sl_game);
	else if (keycode == 119 || keycode == 65362)
		sl_displace_player(sl_game, 'U');
	else if (keycode == 97 || keycode == 65361)
		sl_displace_player(sl_game, 'L');
	else if (keycode == 115 || keycode == 65364)
		sl_displace_player(sl_game, 'D');
	else if (keycode == 100 || keycode == 65363)
		sl_displace_player(sl_game, 'R');
	return (keycode);
}

int	close_window(t_game *sl_game)
{
	mlx_destroy_window(sl_game->grph.mlx, sl_game->grph.win);
	sl_clear_all(sl_game);
	exit(0);
	return (0);
}

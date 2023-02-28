/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utility_hooks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:58:10 by samartin          #+#    #+#             */
/*   Updated: 2023/02/28 16:02:59 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_controls(int keycode, t_game *sl_game)
{
	ft_printf("%i\n", keycode);
	if (keycode == 53)
		close_by_esc(&(sl_game->grph));
	else if (keycode == 13 || keycode == 126)
		sl_displace_player(sl_game, 'U');
	else if (keycode == 0 || keycode == 123)
		sl_displace_player(sl_game, 'L');
	else if (keycode == 1 || keycode == 125)
		sl_displace_player(sl_game, 'D');
	else if (keycode == 2 || keycode == 124)
		sl_displace_player(sl_game, 'R');
	return (keycode);
}

int	close_by_esc(t_mlxgrph *grph_int)
{
	mlx_destroy_window(grph_int->mlx, grph_int->win);
	system("leaks -q so_long"); //ojo!
	exit(0);
}

int	close_by_x(t_mlxgrph *grph_int)
{
	mlx_destroy_window(grph_int->mlx, grph_int->win);
	system("leaks -q so_long"); //ojo!
	exit(0);
	return (0);
}

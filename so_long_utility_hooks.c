/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utility_hooks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:58:10 by samartin          #+#    #+#             */
/*   Updated: 2023/02/23 14:52:18 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_controls(int	keycode, t_mlxgrph *grph)
{
	if (keycode == 53)
		close_by_esc(grph);
	else if	(keycode == 13 || keycode == 62)
		close_by_esc(grph);
	else if	(keycode == 0 || keycode == 59)
		close_by_esc(grph);
	else if	(keycode == 1 || keycode == 61)
		close_by_esc(grph);
	else if	(keycode == 2 || keycode == 60)
		close_by_esc(grph);
	return (keycode);	
}

int	close_by_esc(t_mlxgrph *grph)
{
	mlx_destroy_window(grph->mlx, grph->win);
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

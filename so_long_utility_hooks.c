/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utility_hooks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:58:10 by samartin          #+#    #+#             */
/*   Updated: 2023/02/16 15:09:43 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_by_esc(int keycode, t_mlxgui *gui)
{
	if (keycode == 53)
	{
		mlx_destroy_window(gui->mlx, gui->win);
		exit(0);
	}
	return (keycode);
}

int	close_by_x(t_mlxgui *gui)
{
	mlx_destroy_window(gui->mlx, gui->win);
	exit(0);
	return (0);
}
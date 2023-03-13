/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:35:00 by samartin          #+#    #+#             */
/*   Updated: 2023/03/10 15:46:13 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	sl_error_exits(int code)
{
	if (code == 101)
		ft_printf("Error\n Usage is \"so_long [map file .ber]\"\n");
	else if (code == 102)
		ft_printf("Error\nCould not read .ber map\n");
	else if (code == 103)
		ft_printf("Error\nUnable to allocate memory\n");
	else if (code == 104)
		ft_printf("Error\nWrong map in .ber file\n");
	else if (code == 105)
		ft_printf("Error\nUnable to load sprites\n");
	else
		ft_printf("Error\nUntracked error\n");
	exit(-1);
}

int	sl_load_process(int argc, char **argv, t_list *map, t_game *sl_game)
{
	if (argc != 2)
		sl_error_exits(101);
	map = sl_load_map(argv[1]);
	if (!map)
		sl_error_exits(102);
	sl_game->map = sl_parse_map(map);
	if (!(sl_game->map))
		sl_error_exits(103);
	if (!sl_validate_map(sl_game->map))
		sl_error_exits(104);
	sl_build_scene(sl_game);
	return (1);
}

void	sl_play(t_game sl_game)
{
	sl_game.grph.mlx = mlx_init();
	sl_game.grph.win = mlx_new_window(sl_game.grph.mlx, \
			(sl_game.map_size.x * SPR_SZ), (sl_game.map_size.y \
			* SPR_SZ), "So Long");
	if (sl_load_xpms(&sl_game) == -1)
	{
		sl_clear_all(&sl_game);
		sl_error_exits(105);
	}
	mlx_loop_hook(sl_game.grph.mlx, render_frame, &sl_game);
	mlx_hook(sl_game.grph.win, 2, 1L << 0, sl_controls, &sl_game);
	mlx_hook(sl_game.grph.win, 17, 0L, close_window, &sl_game);
	mlx_loop(sl_game.grph.mlx);
}

int	main(int argc, char **argv)
{
	t_list	*map;
	t_game	sl_game;

	map = NULL;
	if (sl_load_process(argc, argv, map, &sl_game) == -1)
		return (-1);
	sl_play(sl_game);
	return (0);
}

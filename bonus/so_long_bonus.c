/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:35:00 by samartin          #+#    #+#             */
/*   Updated: 2023/03/02 12:23:26 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//¡CUIDAO, MELÓN
//QUE AÚN HAY COMENTARIOS INLINE!

#include "so_long.h"

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

void	sl_build_scene(t_game *sl_game)
{
	t_vec2	xy;

	sl_game->map_size.x = 0;
	while (sl_game->map[0][sl_game->map_size.x])
		sl_game->map_size.x++;
	sl_game->map_size.y = 0;
	while (sl_game->map[sl_game->map_size.y])
		sl_game->map_size.y++;
	sl_game->char_pos = sl_get_pos(sl_game->map, 'P');
	sl_game->map[sl_game->char_pos.y][sl_game->char_pos.x] = '0';
	sl_game->moves = 0;
	sl_game->coins = 0;
	xy.y = 0;
	while (sl_game->map[xy.y])
	{
		xy.x = 0;
		while (sl_game->map[xy.y][xy.x])
		{
			if (sl_game->map[xy.y][xy.x] == 'C')
				sl_game->coins++;
			xy.x++;
		}
		xy.y++;
	}
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
			(sl_game.map_size.x * SPR_SIZE), (sl_game.map_size.y \
			* SPR_SIZE), "So Long");
	sl_game.char_spr.img = NULL;
	sl_game.coin_spr.img = NULL;
	sl_game.empty_spr.img = NULL;
	sl_game.exit_spr.img = NULL;
	sl_game.wall_spr.img = NULL;
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

void	check_leaks()
{
	system("leaks -q so_long");
}

int	main(int argc, char **argv)
{
	t_list	*map;
	t_game	sl_game;
	
	atexit(check_leaks);
	map = NULL;
	if (sl_load_process(argc, argv, map, &sl_game) == -1)
		return (-1);
	sl_play(sl_game);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:35:00 by samartin          #+#    #+#             */
/*   Updated: 2023/02/22 13:39:42 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_build_scene(t_game *sl_game)
{
	t_vec2	xy;

	xy.x = 0;
	while (sl_game->map[0][xy.x])
		xy.x++;
	sl_game->map_size.x = xy.x;
	xy.y = 0;
	while (sl_game->map[xy.y])
		xy.y++;
	sl_game->map_size.y = xy.y;
	sl_game->char_pos = sl_get_pos(sl_game->map, 'P');
}

int	sl_load_process(int argc, char **argv, t_list *map, t_game *sl_game)
{
	if (argc != 2)
	{
		ft_printf("Error\n Usage is \"so_long [map file .ber]\"\n");
		return (-1);
	}
	map = sl_load_map(argv[1]);
	if (!map)
	{
		ft_printf("Error\nCould not read .ber map\n");
		return (-1);
	}
	sl_game->map = sl_parse_map(map);
	if (!(sl_game->map))
	{
		ft_printf("Error\nUnable to allocate memory\n");
		return (-1);
	}
	if (!sl_validate_map(sl_game->map))
	{
		ft_printf("Error\nWrong map in .ber file\n");
		return (-1);
	}
	sl_build_scene(sl_game);
	return (1);
}

void	sl_play(t_game sl_game)
{
	t_mlxgui	gui;
	t_data		img;

	gui.mlx = mlx_init();
	gui.win = mlx_new_window(gui.mlx, (sl_game.map_size.x * SPRITE_SIZE),
			(sl_game.map_size.y * SPRITE_SIZE), "So Long");
	sl_game.empty_spr.img = mlx_new_image(gui.mlx, SPRITE_SIZE, SPRITE_SIZE);
	//sl_game.empty_spr.img = mlx_xpm_file_to_image(gui.mlx, "./empty.xpm", &img_width, &img_height);
	sl_game.empty_spr.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	mlx_put_image_to_window(gui.mlx, gui.win, img.img, 0, 0);
	//mlx_loop_hook(gui.mlx, render_frame, &sl_game);
	mlx_hook(gui.win, 2, 1L << 0, close_by_esc, &gui);
	mlx_hook(gui.win, 17, 0L, close_by_x, &gui);
	mlx_loop(gui.mlx);
}

int	main(int argc, char **argv)
{
	t_list	*map;
	t_game	sl_game;

	map = NULL;
	if (sl_load_process(argc, argv, map, &sl_game) == -1)
		return (-1);
	sl_play(sl_game);
	system("leaks -q so_long");
	return (0);
}

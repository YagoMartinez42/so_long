/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:35:00 by samartin          #+#    #+#             */
/*   Updated: 2023/02/20 13:59:44 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	return (1);
}

void	sl_play(t_game sl_game)
{
	t_mlxgui	gui;
	t_data		img;

	gui.mlx = mlx_init();
	gui.win = mlx_new_window(gui.mlx, 1600, 900, "So Long");
	img.img = mlx_new_image(gui.mlx, 1600, 900);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	mlx_put_image_to_window(gui.mlx, gui.win, img.img, 0, 0);
	mlx_loop_hook(gui.mlx, render_frame, &sl_game);
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

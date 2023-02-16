/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:35:00 by samartin          #+#    #+#             */
/*   Updated: 2023/02/16 12:12:43 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int	main(int argc, char **argv)
{
	t_list	*map;
	t_game	sl_game;

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
	sl_game.map = sl_parse_map(map);
	if (!sl_game.map)
	{
		ft_printf("Error\nUnable to allocate memory\n");
		return (-1);
	}
	if (!sl_validate_map(sl_game.map))
	{
		ft_printf("Error\nWrong map in .ber file\n");
		return (-1);
	}

	int x = 0;
	int y = 0;
	while (sl_game.map[y])
	{
		x = 0;
		while(sl_game.map[y][x])
		{
			ft_printf("%c", sl_game.map[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
	}
	//sl_play();
	system("leaks -q so_long");
	return (0);
}

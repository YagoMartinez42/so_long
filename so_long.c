/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:35:00 by samartin          #+#    #+#             */
/*   Updated: 2023/02/14 16:31:17 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	lst_print_str(void *content)
{
	ft_printf("%s", content);
}

int	sl_validate_map(char **map)
{
	size_t	map_len;
	int		contents;

	map_len = ft_strlen(map[0]);
	contents = 0;
	if (!(val_walls(map, map_len)))
		return (0);
	contents = val_contents(map, map_len);
	if (contents < 7 || contents % 4 != 3)
		return (0);
	return (1);
}

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
		return (-1);
	sl_game.map =  sl_parse_map(map);
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
	//sl_play();
	system("leaks -q so_long");
	return (0);
}

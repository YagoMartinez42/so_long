/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:16:21 by samartin          #+#    #+#             */
/*   Updated: 2023/02/15 17:16:34 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	val_walls(char **map, size_t map_len)
{
	size_t	y;

	y = 0;
	while (map[y])
	{
		if (y == 0 || map[y + 1] == NULL)
		{
			if (ft_strspn(map[y], "1") != map_len)
				return (0);
		}
		else if (map[y][0] != '1'
				|| map[y][map_len - 1] != '1')
			return (0);
		if (ft_strlen(map[y]) != map_len)
			return (0);
		y++;
	}
	return (1);
}

static int	val_cep(char *line, int contents)
{
	if (ft_strchr(line, 'C'))
		contents += 4;
	if (ft_strchr(line, 'E'))
	{
		if (contents & 2)
			return (0);
		else
			contents += 2;
	}
	if (ft_strchr(line, 'P'))
	{
		if (contents & 1)
			return (0);
		else
			contents += 1;
	}
	return (contents);
}

static int	val_contents(char **map, size_t map_len)
{
	int		contents;
	size_t	y;

	y = 0;
	contents = 0;
	while (map[y])
	{
		if (ft_strspn(map[y], "01CEP") == map_len)
			contents = val_cep(map[y], contents);
		else
			return (0);
		y++;
	}
	return (contents);
}

static int	val_path(char **map)
{
	char	**map_copy;
	size_t	len;
	size_t	i;

	map_copy = sl_copy_matrix(map);
	sl_flood(map_copy, sl_get_pos(map_copy, 'P'));
	len = ft_strlen(map_copy[0]);
	i = 0;
	while (map_copy[i])
	{
		if (ft_strspn(map_copy[i], "10F") != len)
		{
			sl_free_matrix(map_copy);
			return (0);
		}
		i++;
	}
	sl_free_matrix(map_copy);
	return (1);
}

int	sl_validate_map(char **map)
{
	t_vec2	map_len;
	int		contents;

	map_len.x = ft_strlen(map[0]);
	contents = 0;
	if (!(val_walls(map, map_len.x)))
		return (0);
	contents = val_contents(map, map_len.x);
	if (contents < 7 || contents % 4 != 3)
		return (0);
	if (!(val_path(map)))
		return (0);
	return (1);
}

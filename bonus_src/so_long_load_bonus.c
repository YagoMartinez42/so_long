/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_load_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:11:51 by samartin          #+#    #+#             */
/*   Updated: 2023/03/07 11:18:32 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_list	*sl_addline(t_list *map, char *line)
{
	t_list	*node;

	node = ft_lstnew(line);
	if (!node)
	{
		ft_printf("Error\nCould not allocate memory.\n");
		ft_lstclear(&map, lst_free_str);
		return (NULL);
	}
	ft_lstadd_back(&map, node);
	return (map);
}

static void	sl_rem_nl(t_list *map)
{
	t_list	*line_node;
	size_t	map_len;

	if (map)
	{
		map_len = (ft_strlen(map->content)) - 1;
		line_node = map;
		while (line_node)
		{
			if (((char *)line_node->content)[map_len] == '\n')
				((char *)line_node->content)[map_len] = '\0';
			line_node = line_node->next;
		}
	}
}

t_list	*sl_load_map(char *map_file)
{
	int		fd_ber;
	char	*line;
	t_list	*map;

	fd_ber = open(map_file, O_RDONLY);
	if (fd_ber < 0)
		return (NULL);
	map = NULL;
	while (1)
	{
		line = get_next_line(fd_ber);
		if (line)
		{
			map = sl_addline(map, line);
			if (!map)
				return (NULL);
		}
		else
			break ;
	}
	sl_rem_nl(map);
	return (map);
}

char	**sl_parse_map(t_list *map)
{
	char	**matrix;
	t_list	*node;
	size_t	i;

	matrix = malloc((ft_lstsize(map) + 1) * sizeof(char *));
	if (!matrix)
		return (NULL);
	node = map;
	i = 0;
	while (node)
	{
		matrix[i] = malloc((ft_strlen(node->content) + 1) * sizeof(char));
		if (!(matrix[i]))
		{
			sl_free_matrix(matrix);
			return (NULL);
		}
		if (!(ft_strcpy(matrix[i], node->content)))
			return (NULL);
		node = node->next;
		i++;
	}
	matrix[i] = NULL;
	ft_lstclear(&map, lst_free_str);
	return (matrix);
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

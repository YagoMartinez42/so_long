/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_load.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:22:51 by samartin          #+#    #+#             */
/*   Updated: 2023/02/14 16:35:11 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	sl_addline(t_list *map, char *line)
{
	t_list	*node;

	node = ft_lstnew(line);
	if (!node)
	{
		ft_printf("Error\nCould not allocate memory.\n");
		ft_lstclear(&map, lst_free_str);
		return (0);
	}
	ft_lstadd_back(&map, node);
	return (1);
}

static void	sl_rem_nl(t_list *map)
{
	t_list	*line_node;
	size_t	map_len;

	map_len = ft_strlen(map->content) - 1;
	line_node = map;
	while (line_node)
	{
		if (((char *)line_node->content)[map_len] == '\n')
			((char *)line_node->content)[map_len] = '\0';
		line_node = line_node->next;
	}
}

t_list	*sl_load_map(char *map_file)
{
	int		fd_ber;
	char	*line;
	t_list	*map;

	fd_ber = open(map_file, O_RDONLY);
	if (fd_ber < 0)
	{
		ft_printf("Error\n While opening file.\n");
		return (NULL);
	}
	map = NULL;
	while (1)
	{
		line = get_next_line(fd_ber);
		if (line)
		{
			if (!(sl_addline(map, line)))
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
			free_matrix(matrix);
			return (NULL);
		}
		if (ft_strcpy(node->content, matrix[i]))
			i++;
		else
			return (NULL);
	}
	matrix[i] = NULL;
	ft_lstclear(&map, lst_free_str);
	return (matrix);
}

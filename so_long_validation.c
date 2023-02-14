/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:16:21 by samartin          #+#    #+#             */
/*   Updated: 2023/02/14 16:36:30 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	val_walls(char **map, size_t map_len)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (map[y] != NULL) //here
	{
		if (line_node == map || line_node->next == NULL)
		{
			if (ft_strspn(line_node->content, "1") != map_len)
				return (0);
		}
		else if (((char *)line_node->content)[0] != '1'
				|| ((char *)line_node->content)[map_len - 1] != '1')
			return (0);
		if (ft_strlen(line_node->content) != map_len)
			return (0);
		line_node = line_node->next;
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

int	val_contents(t_list *map, size_t map_len)
{
	t_list	*line_node;
	int		contents;

	line_node = map;
	contents = 0;
	while (line_node)
	{
		if (ft_strspn(line_node->content, "01CEP") == map_len)
			contents = val_cep(line_node->content, contents);
		else
			return (0);
		line_node = line_node->next;
	}
	return (contents);
}

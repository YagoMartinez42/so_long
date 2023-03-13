/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:16:26 by samartin          #+#    #+#             */
/*   Updated: 2023/03/02 11:01:54 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strspn(char *str, char *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (set[j])
		{
			if (str[i] == set[j])
				break ;
			j++;
		}
		if (set[j] == '\0')
			return (i);
		i++;
	}
	return (i);
}

char	**sl_copy_matrix(char **matrix)
{
	char	**matrix_copy;
	size_t	i;

	i = 0;
	while (matrix[i])
		i++;
	matrix_copy = malloc((i + 1) * sizeof(char *));
	i = 0;
	while (matrix[i])
	{
		matrix_copy[i] = malloc((ft_strlen(matrix[i]) + 1) * sizeof(char));
		ft_strcpy(matrix_copy[i], matrix[i]);
		i++;
	}
	matrix_copy[i] = NULL;
	return (matrix_copy);
}

void	sl_flood(char **matrix, t_vec2 pos)
{
	if (pos.y < 0 || !(matrix[pos.y]) || pos.x < 0 || !(matrix[pos.y][pos.x])
		|| !(ft_strchr("0EPC", matrix[pos.y][pos.x])))
		return ;
	matrix[pos.y][pos.x] = 'F';
	sl_flood(matrix, (t_vec2){pos.x + 1, pos.y});
	sl_flood(matrix, (t_vec2){pos.x - 1, pos.y});
	sl_flood(matrix, (t_vec2){pos.x, pos.y + 1});
	sl_flood(matrix, (t_vec2){pos.x, pos.y - 1});
}

t_vec2	sl_get_pos(char **matrix, char item)
{
	t_vec2	pos;

	pos.y = 0;
	while (matrix[pos.y])
	{
		pos.x = 0;
		while (matrix[pos.y][pos.x])
		{
			if (matrix[pos.y][pos.x] == item)
				return (pos);
			pos.x++;
		}
		pos.y++;
	}
	return ((t_vec2){(size_t)(-1), (size_t)(-1)});
}

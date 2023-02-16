/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:32:47 by samartin          #+#    #+#             */
/*   Updated: 2023/02/15 17:01:23 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#include "libft/libft.h"
#include "libft/filem/filem.h"
#include "libft/lists/lists.h"

typedef struct	game
{
	char	**map;
}	t_game;

typedef struct	s_vec2
{
	size_t	x;
	size_t	y;
}	t_vec2;

t_list	*sl_load_map(char *map_file);
char	**sl_parse_map(t_list *map);
int		sl_validate_map(char **map);
size_t	ft_strspn(char *str, char *set);
char	**sl_copy_matrix(char **matrix);
void	sl_flood(char **matrix, t_vec2 pos);
t_vec2	sl_get_pos(char **matrix, char item);
void	sl_free_matrix(char **matrix);

#endif
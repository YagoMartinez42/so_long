/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:32:47 by samartin          #+#    #+#             */
/*   Updated: 2023/02/14 13:43:56 by samartin         ###   ########.fr       */
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
	size_t	x;
	size_t	y;
}	t_game;

t_list	*sl_load_map(char *map_file);
char	**sl_parse_map(t_list *map);
int		sl_validate_map(t_list	*map);
void	val_rem_nl(t_list *map, size_t map_len);
int		val_walls(t_list *map, size_t map_len);
int		val_contents(t_list *map, size_t map_len);
size_t	ft_strspn(char *str, char *set);
void	lst_free_str(void *content);
void	free_matrix(char **matrix);

#endif
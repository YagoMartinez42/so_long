/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:32:47 by samartin          #+#    #+#             */
/*   Updated: 2023/02/20 13:14:18 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "libft/filem/filem.h"
# include "libft/lists/lists.h"
# include "mlx/mlx.h"

typedef struct s_vec2
{
	size_t	x;
	size_t	y;
}		t_vec2;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

typedef struct s_mlxgui
{
	void	*mlx;
	void	*win;
}		t_mlxgui;

typedef struct s_game
{
	char	**map;
	size_t	coins;
}		t_game;

t_list	*sl_load_map(char *map_file);
char	**sl_parse_map(t_list *map);
int		sl_validate_map(char **map);
size_t	ft_strspn(char *str, char *set);
char	**sl_copy_matrix(char **matrix);
void	sl_flood(char **matrix, t_vec2 pos);
t_vec2	sl_get_pos(char **matrix, char item);
void	sl_free_matrix(char **matrix);
int		close_by_esc(int keycode, t_mlxgui *gui);
int		close_by_x(t_mlxgui *gui);
int		render_frame(t_game *sl_game);

#endif
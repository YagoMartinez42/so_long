/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:32:47 by samartin          #+#    #+#             */
/*   Updated: 2023/03/07 11:17:11 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# ifndef SPR_SIZE
#  define SPR_SIZE 48
# endif
# ifndef CHAR_FILETMPL
#  define CHAR_FILETMPL "sprites/char48_"
# endif
# ifndef COIN_FILE
#  define COIN_FILE "sprites/coin48.xpm"
# endif
# ifndef EMPTY_FILE
#  define EMPTY_FILE "sprites/empty48.xpm"
# endif
# ifndef EXIT_FILE
#  define EXIT_FILE "sprites/exit48.xpm"
# endif
# ifndef WALL_FILE
#  define WALL_FILE "sprites/wall48.xpm"
# endif
# include "../libft/libft.h"
# include "../libft/filem/filem.h"
# include "../libft/lists/lists.h"
# include <mlx.h>

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
	int		wd;
	int		ht;
}		t_data;

typedef struct s_mlxgrph
{
	void	*mlx;
	void	*win;
}		t_mlxgrph;

typedef struct s_game
{
	char		**map;
	int			key_on;
	t_mlxgrph	grph;
	size_t		coins;
	size_t		moves;
	t_vec2		map_size;
	t_vec2		char_pos;
	size_t		char_step;
	size_t		char_dir;
	t_data		char_spr[12];
	t_data		coin_spr;
	t_data		empty_spr;
	t_data		exit_spr;
	t_data		wall_spr;
}		t_game;

t_list	*sl_load_map(char *map_file);
char	**sl_parse_map(t_list *map);
int		sl_validate_map(char **map);
size_t	ft_strspn(char *str, char *set);
char	**sl_copy_matrix(char **matrix);
void	sl_flood(char **matrix, t_vec2 pos);
int		sl_load_xpms(t_game *sl_game);
t_vec2	sl_get_pos(char **matrix, char item);
void	sl_build_scene(t_game *sl_game);
void	sl_free_matrix(char **matrix);
void	lst_free_str(void *content);
void	sl_clear_all(t_game *sl_game);
int		sl_controls(int keycode, t_game *sl_game);
void	sl_displace_player(t_game *sl_game, size_t dis_dir);
void	sl_check_conditions(t_game *sl_game, t_vec2 pos);
int		close_window(t_game *sl_game);
int		render_frame(t_game *sl_game);

#endif
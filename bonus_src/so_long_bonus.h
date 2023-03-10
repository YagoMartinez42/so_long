/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:32:47 by samartin          #+#    #+#             */
/*   Updated: 2023/03/13 12:27:59 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# ifndef SPR_SZ
#  define SPR_SZ 48
# endif
# ifndef ANIM_ST
#  define ANIM_ST 6
# endif
# ifndef CHR_SPR_CNT
#  define CHR_SPR_CNT 12
# endif
# ifndef CHAR_FILETMPL
#  define CHAR_FILETMPL "bonus_sprites/char48_"
# endif
# ifndef COIN_FILE
#  define COIN_FILE "bonus_sprites/coin48.xpm"
# endif
# ifndef EMPTY_FILE
#  define EMPTY_FILE "bonus_sprites/empty48.xpm"
# endif
# ifndef EXIT_FILE
#  define EXIT_FILE "bonus_sprites/exit48.xpm"
# endif
# ifndef WALL_FILE
#  define WALL_FILE "bonus_sprites/wall48.xpm"
# endif
# include "../libft/libft.h"
# include "../libft/filem/filem.h"
# include "../libft/lists/lists.h"
# include <mlx.h>
# include <time.h>

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
	int			game_on;
	t_mlxgrph	grph;
	size_t		coins;
	size_t		moves;
	clock_t		anim_start;
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
t_vec2	sl_get_step(t_game *sl_game);
void	sl_chrono(t_game *sl_game);
void	sl_check_conditions(t_game *sl_game, t_vec2 pos);
int		close_window(t_game *sl_game);
int		render_frame(t_game *sl_game);

#endif
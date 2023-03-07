/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_img_load_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:28:17 by samartin          #+#    #+#             */
/*   Updated: 2023/03/07 11:25:59 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	sl_load_player_anims(t_game *sl_game)
{
	size_t	i;
	char	*filepath;

	filepath = malloc(40 * sizeof(char));
	i = 0;
	while (i < 12)
	{
		filepath = ft_strcat(ft_strcat(CHAR_FILETMPL, ft_itoa(i)), ".xpm");
ft_printf("file: %s\n", filepath);
		sl_game->char_spr[i].img = mlx_xpm_file_to_image(sl_game->grph.mlx, \
			filepath, &(sl_game->char_spr[i].wd), &(sl_game->char_spr[i].ht));
		if (!sl_game->char_spr[i].img)
			return (-1);
		i++;
	}
	return (1);
}

void	sl_set_img20(t_game *sl_game)
{
	sl_game->char_pos.x *= SPR_SIZE;
	sl_game->char_pos.y *= SPR_SIZE;
	sl_game->key_on = 1;
	sl_game->char_step = 0;
	sl_game->char_dir = 1;
	sl_game->coin_spr.img = NULL;
	sl_game->empty_spr.img = NULL;
	sl_game->exit_spr.img = NULL;
	sl_game->wall_spr.img = NULL;
}

int	sl_load_xpms(t_game *sl_game)
{
	sl_set_img20(sl_game);
	if (!sl_load_player_anims(sl_game))
		return (-1);
	sl_game->coin_spr.img = mlx_xpm_file_to_image(sl_game->grph.mlx, \
			COIN_FILE, &(sl_game->coin_spr.wd), &(sl_game->coin_spr.ht));
	if (!sl_game->coin_spr.img)
		return (-1);
	sl_game->empty_spr.img = mlx_xpm_file_to_image(sl_game->grph.mlx, \
			EMPTY_FILE, &(sl_game->empty_spr.wd), &(sl_game->empty_spr.ht));
	if (!sl_game->empty_spr.img)
		return (-1);
	sl_game->exit_spr.img = mlx_xpm_file_to_image(sl_game->grph.mlx, \
			EXIT_FILE, &(sl_game->exit_spr.wd), &(sl_game->exit_spr.ht));
	if (!sl_game->exit_spr.img)
		return (-1);
	sl_game->wall_spr.img = mlx_xpm_file_to_image(sl_game->grph.mlx, \
			WALL_FILE, &(sl_game->wall_spr.wd), &(sl_game->wall_spr.ht));
	if (!sl_game->wall_spr.img)
		return (-1);
	return (1);
}

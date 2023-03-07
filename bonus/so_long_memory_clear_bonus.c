/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_memory_clear_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:56:39 by samartin          #+#    #+#             */
/*   Updated: 2023/03/06 13:55:16 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	lst_free_str(void *content)
{
	free(content);
}

void	sl_free_matrix(char **matrix)
{
	size_t	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	sl_clear_all(t_game *sl_game)
{
	size_t	i;

	if (sl_game->coin_spr.img)
		mlx_destroy_image(sl_game->grph.mlx, sl_game->coin_spr.img);
	if (sl_game->empty_spr.img)
		mlx_destroy_image(sl_game->grph.mlx, sl_game->empty_spr.img);
	if (sl_game->exit_spr.img)
		mlx_destroy_image(sl_game->grph.mlx, sl_game->exit_spr.img);
	if (sl_game->wall_spr.img)
		mlx_destroy_image(sl_game->grph.mlx, sl_game->wall_spr.img);
	i = 0;
	while (i < 12)
	{
		if (sl_game->char_spr[i].img)
			mlx_destroy_image(sl_game->grph.mlx, sl_game->char_spr[i].img);
		i++;
	}
	sl_free_matrix(sl_game->map);
}

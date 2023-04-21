/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 22:16:02 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/04/20 22:16:11 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_mlx(t_cub3d *cub3d)
{
	cub3d->mlx_ptr = mlx_init();
	if (cub3d->mlx_ptr == NULL)
		return (exit_with_message(ERROR_CODE, MLX_ERROR_MESSAGE));
	cub3d->win_ptr = mlx_new_window(
			cub3d->mlx_ptr,
			cub3d->map.columns * TILE_SIZE,
			cub3d->map.rows * TILE_SIZE,
			GAME_NAME);
	if (cub3d->win_ptr == NULL)
	{
		free(cub3d->win_ptr);
		return (exit_with_message(ERROR_CODE, MLX_ERROR_MESSAGE));
	}
	return (0);
}

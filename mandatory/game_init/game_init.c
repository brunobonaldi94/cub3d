/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 22:16:02 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/04/21 16:00:50 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	init_mlx(t_cub3D *cub3D);
void	init_variables(t_cub3D *cub3D, char *argv[]);

int	init_game(t_cub3D *cub3D, char *argv[])
{
	init_mlx(cub3D);
	init_variables(cub3D, argv);
	return (TRUE);
}

int	init_mlx(t_cub3D *cub3D)
{
	cub3D->mlx_ptr = mlx_init();
	if (cub3D->mlx_ptr == NULL)
		return (exit_with_message(ERROR_CODE, MLX_ERROR_MESSAGE));
	cub3D->win_ptr = mlx_new_window(
			cub3D->mlx_ptr,
			cub3D->map.columns * TILE_SIZE,
			cub3D->map.rows * TILE_SIZE,
			GAME_NAME);
	if (cub3D->win_ptr == NULL)
	{
		free(cub3D->mlx_ptr);
		return (exit_with_message(ERROR_CODE, MLX_ERROR_MESSAGE));
	}
	return (SUCCESS_CODE);
}

void	init_variables(t_cub3D *cub3D, char *argv[])
{
	cub3D->map.columns = 0;
	cub3D->map.rows = 0;
	cub3D->map.map_matrix = NULL;
	cub3D->map.map_file_path = argv[1];
	cub3D->map.no_file_path = NULL;
	cub3D->map.no_file_path = NULL;
	cub3D->map.so_file_path = NULL;
	cub3D->map.we_file_path = NULL;
	cub3D->map.ea_file_path = NULL;
	cub3D->map.floor_color = NULL;
	cub3D->map.ceil_color = NULL;
}

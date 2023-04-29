/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 22:16:02 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/04/23 17:01:30 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		init_mlx(t_cubd *cub3D);
void	init_variables(t_cubd *cub3D);

int	init_game(t_cubd *cub3D, char *argv[])
{
	(void) argv;
	init_variables(cub3D);
	//validate_map(cub3D, argv[1]);
	init_mlx(cub3D);
	cub3D->player = malloc(sizeof(t_player));
	init_player(cub3D, cub3D->player);
    cub3D->game->window.win_ptr = cub3D->win_ptr; 
    cub3D->game->mlx_ptr = cub3D->mlx_ptr;
	return (TRUE);
}

int	init_mlx(t_cubd *cub3D)
{
	cub3D->game->map = generate_map(PATH_MAP);
	cub3D->game->window = get_window_size(cub3D->game->map);
	cub3D->mlx_ptr = mlx_init();
	if (cub3D->mlx_ptr == NULL)
		return (exit_with_message(ERROR_CODE, MLX_ERROR_MESSAGE));
	cub3D->win_ptr = mlx_new_window(
			cub3D->mlx_ptr,
			cub3D->game->window.width,
			cub3D->game->window.height,
			GAME_NAME);
	if (cub3D->win_ptr == NULL)
	{
		free(cub3D->mlx_ptr);
		return (exit_with_message(ERROR_CODE, MLX_ERROR_MESSAGE));
	}
	return (SUCCESS_CODE);
}

void	init_colors(t_color *color)
{
	color->color_str = NULL;
	color->r = -1;
	color->g = -1;
	color->b = -1;
	color->alpha = 1;
}

void	init_variables(t_cubd *cub3D)
{
	cub3D->mlx_ptr = NULL;
	cub3D->win_ptr = NULL;
	cub3D->map.map_list = NULL;
	cub3D->map.dimensions.columns = 0;
	cub3D->map.dimensions.rows = 0;
	cub3D->map.map_matrix = NULL;
	init_colors(&cub3D->map.ceiling_color);
	init_colors(&cub3D->map.floor_color);
	cub3D->map.map_file.name = NULL;
	cub3D->map.map_file.fd = UNINITIALIZED_FD;
	cub3D->map.so_file = NULL;
	cub3D->map.no_file = NULL;
	cub3D->map.we_file = NULL;
	cub3D->map.ea_file = NULL;
}

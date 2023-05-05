/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 22:16:02 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/04/30 14:04:25 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		init_mlx(t_cubd *cub3D);
void	init_variables(t_cubd *cub3D);

int	init_game(t_cubd *cub3D, char *argv[])
{
	init_variables(cub3D);
	cub3D->player = (t_player *)malloc(sizeof(t_player));
	cub3D->rays = malloc(sizeof(t_ray) * NUM_RAYS);
	init_player(cub3D, cub3D->player);
	validate_map(cub3D, argv[1]);
	init_mlx(cub3D);
	cub3D->game->window.win_ptr = cub3D->win_ptr;
	cub3D->game->mlx_ptr = cub3D->mlx_ptr;
	return (TRUE);
}

int	init_mlx(t_cubd *cub3D)
{
	cub3D->game->map = cub3D->map.map_matrix;
	cub3D->game->window = get_window(&cub3D->map);
	cub3D->mlx_ptr = mlx_init();
	if (cub3D->mlx_ptr == NULL)
		return (exit_with_message(ERROR_CODE, MLX_ERROR_MESSAGE));
	cub3D->win_ptr = mlx_new_window(
			cub3D->mlx_ptr,
			WINDOW_WIDTH,
			WINDOW_HEIGHT,
			GAME_NAME);
	if (cub3D->win_ptr == NULL)
	{
		free(cub3D->mlx_ptr);
		return (exit_with_message(ERROR_CODE, MLX_ERROR_MESSAGE));
	}
	ft_printf("Game has started!");
	return (SUCCESS_CODE);
}

void	init_variables(t_cubd *cub3D)
{
	cub3D->mlx_ptr = NULL;
	cub3D->win_ptr = NULL;
	init_map(&cub3D->map);
}

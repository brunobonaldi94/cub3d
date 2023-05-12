/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 22:16:02 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/10 23:13:34 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int		init_mlx(t_cubd *cub3D);
void	init_game_variables(t_cubd *cub3D);

int	init_game(t_cubd *cub3D, char *argv[])
{
	cub3D->mlx_ptr = NULL;
	cub3D->win_ptr = NULL;
	init_map(&cub3D->map);
	init_player(cub3D);
	validate_map(cub3D, argv[1]);
	init_mlx(cub3D);
	init_game_variables(cub3D);
	return (TRUE);
}

void	init_game_variables(t_cubd *cub3D)
{
	cub3D->game->window = get_window(&cub3D->map);
	cub3D->game->window.win_ptr = cub3D->win_ptr;
	cub3D->game->mlx_ptr = cub3D->mlx_ptr;
	cub3D->game->map = cub3D->map.map_matrix;
}

int	init_mlx(t_cubd *cub3D)
{
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
	ft_printf("Game has started!\n");
	return (SUCCESS_CODE);
}

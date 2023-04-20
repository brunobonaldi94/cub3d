/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:41:30 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/04/19 22:56:19 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(char *message)
{
	ft_printf("%s\n%s\n", "Error", message);
}

int	exit_with_message(int status_code, char *message)
{
	print_error(message);
	exit(status_code);
}

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

int	main(void)
{
	t_cub3d	cub3d;

	cub3d.map.columns = 20;
	cub3d.map.rows = 20;
	init_mlx(&cub3d);
	mlx_loop(cub3d.mlx_ptr);
	return (0);
}

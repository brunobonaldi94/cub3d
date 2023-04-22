/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:32:36 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/04/21 22:41:09 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	destroy_window(t_cubd *cub3D);
void	destroy_display(t_cubd *cub3D);

void	close_fd(int fd)
{
	if (fd < 0)
		return ;
	close(fd);
}

int	game_exit(t_cubd *cub3D)
{
	destroy_window(cub3D);
	destroy_display(cub3D);
	exit(SUCCESS_CODE);
}

void	destroy_window(t_cubd *cub3D)
{
	mlx_destroy_window(cub3D->mlx_ptr, cub3D->win_ptr);
	cub3D->win_ptr = NULL;
}

void	destroy_display(t_cubd *cub3D)
{
	mlx_destroy_display(cub3D->mlx_ptr);
	free(cub3D->mlx_ptr);
}

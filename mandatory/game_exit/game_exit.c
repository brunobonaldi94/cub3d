/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:32:36 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/04/21 16:42:35 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	destroy_window(t_cub3D *cub3D);
void	destroy_display(t_cub3D *cub3D);

void	close_fd(int fd)
{
	if (fd < 0)
		return ;
	close(fd);
}

int	game_exit(t_cub3D *cub3D)
{
	destroy_window(cub3D);
	destroy_display(cub3D);
	exit(SUCCESS_CODE);
}

void	destroy_window(t_cub3D *cub3D)
{
	mlx_destroy_window(cub3D->mlx_ptr, cub3D->win_ptr);
	cub3D->win_ptr = NULL;
}

void	destroy_display(t_cub3D *cub3D)
{
	mlx_destroy_display(cub3D->mlx_ptr);
	free(cub3D->mlx_ptr);
}


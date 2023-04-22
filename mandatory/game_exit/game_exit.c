/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:32:36 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/04/22 18:13:23 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	destroy_window(t_cubd *cub3D);
void	destroy_display(t_cubd *cub3D);
void	clear_map(t_cubd *cub3D);
void	clear_map_matrix(t_cubd *cub3D);

int	game_exit(t_cubd *cub3D)
{
	clear_map(cub3D);
	destroy_window(cub3D);
	destroy_display(cub3D);
	exit(SUCCESS_CODE);
}

void	close_fd(int fd)
{
	if (fd < 0)
		return ;
	close(fd);
}

void	clear_map(t_cubd *cub3D)
{
	ft_free_ptr((void **)&cub3D->map.ceiling_color);
	ft_free_ptr((void **)&cub3D->map.floor_color);
	ft_free_ptr((void **)&cub3D->map.we_file);
	ft_free_ptr((void **)&cub3D->map.so_file);
	ft_free_ptr((void **)&cub3D->map.ea_file);
	ft_free_ptr((void **)&cub3D->map.no_file);
	clear_map_matrix(cub3D);
}

void	clear_map_matrix(t_cubd *cub3D)
{
	int	index;

	index = 0;
	while (index < cub3D->map.dimensions.rows)
	{
		free(cub3D->map.map_matrix[index]);
		index++;
	}
	free(cub3D->map.map_matrix);
}

void	destroy_window(t_cubd *cub3D)
{
	mlx_destroy_window(cub3D->mlx_ptr, cub3D->win_ptr);
	cub3D->win_ptr = NULL;
}

void	destroy_display(t_cubd *cub3D)
{
	mlx_destroy_display(cub3D->mlx_ptr);
	ft_free_ptr((void **)&cub3D->mlx_ptr);
}

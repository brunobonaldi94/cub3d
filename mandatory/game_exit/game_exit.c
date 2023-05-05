/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:32:36 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/04 19:57:07 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	destroy_window(t_cubd *cub3D);
void	destroy_display(t_cubd *cub3D);
void	clear_map(t_cubd *cub3D);
void	game_clear(t_cubd *cub3D);

int	game_exit(t_cubd *cub3D)
{
	game_clear(cub3D);
	exit(SUCCESS_CODE);
}

void	game_clear(t_cubd *cub3D)
{
	clear_map(cub3D);
	clear_player(cub3D);
	destroy_window(cub3D);
	destroy_display(cub3D);
}

void	clear_map(t_cubd *cub3D)
{
	ft_free_ptr((void **)&cub3D->map.ceiling_color.color_str);
	ft_free_ptr((void **)&cub3D->map.floor_color.color_str);
	ft_free_ptr((void **)&cub3D->map.we_file);
	ft_free_ptr((void **)&cub3D->map.so_file);
	ft_free_ptr((void **)&cub3D->map.ea_file);
	ft_free_ptr((void **)&cub3D->map.no_file);
	ft_lstclear(&cub3D->map.map_list, free);
	clear_map_matrix(cub3D);
}

void	destroy_window(t_cubd *cub3D)
{
	if (cub3D->mlx_ptr == NULL && cub3D->win_ptr == NULL)
		return ;
	mlx_destroy_window(cub3D->mlx_ptr, cub3D->win_ptr);
	cub3D->win_ptr = NULL;
}

void	destroy_display(t_cubd *cub3D)
{
	if (cub3D->mlx_ptr == NULL)
		return ;
	mlx_destroy_display(cub3D->mlx_ptr);
	ft_free_ptr((void **)&cub3D->mlx_ptr);
}

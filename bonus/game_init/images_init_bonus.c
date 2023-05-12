/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_init_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:52:37 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/10 23:13:34 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	init_texture(t_cubd *cub3d, t_img *img, char *path)
{
	img->mlx_img = mlx_xpm_file_to_image(
			cub3d->mlx_ptr, path, &img->width, &img->height);
	img->color_buffer = (int *)
		mlx_get_data_addr(img->mlx_img,
			&img->bits_per_pixel,
			&img->line_length,
			&img->endian);
}

void	init_textures(t_cubd *cub3d)
{
	init_texture(cub3d, &cub3d->textures[SO], cub3d->map.so_file);
	init_texture(cub3d, &cub3d->textures[NO], cub3d->map.no_file);
	init_texture(cub3d, &cub3d->textures[WE], cub3d->map.we_file);
	init_texture(cub3d, &cub3d->textures[EA], cub3d->map.ea_file);
}

void	init_img_game(t_cubd *cub3D)
{
	cub3D->img_game.mlx_img = mlx_new_image(cub3D->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	cub3D->img_game.height = WINDOW_HEIGHT;
	cub3D->img_game.width = WINDOW_WIDTH;
	cub3D->img_game.color_buffer = (int *)
		mlx_get_data_addr(cub3D->img_game.mlx_img,
			&cub3D->img_game.bits_per_pixel,
			&cub3D->img_game.line_length,
			&cub3D->img_game.endian);
}

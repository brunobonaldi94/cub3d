/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:52:37 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/08 22:15:09 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_texture(t_cubd *cub3d, t_img *img, char *path)
{
	img->mlx_img = mlx_xpm_file_to_image(
			cub3d->mlx_ptr, path, &img->width, &img->height);
	img->addr =
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

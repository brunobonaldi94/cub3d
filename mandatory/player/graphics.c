/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:52:55 by sjhony-x          #+#    #+#             */
/*   Updated: 2023/05/09 15:52:58 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

int	get_color_pixel(t_cubd *cub3d, int text_num,
	int text_offset_x, int text_offset_y)
{
	return (cub3d->textures[text_num].color_buffer
		[cub3d->textures[text_num].width * text_offset_y + text_offset_x]);
}

void	pixel_put(t_img *img, int x, int y, int color)
{
	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	img->color_buffer[(y * img->width) + x] = color;
}

int	rgb_to_hex(t_color color)
{
	return (color.alpha << 24 | color.r << 16 | color.g << 8 | color.b);
}

void	color_intensity(int *color, double factor)
{
	int	a;
	int	r;
	int	g;
	int	b;

	a = (*color & 0xFF000000);
	r = (*color & 0x00FF0000) * factor;
	g = (*color & 0x0000FF00) * factor;
	b = (*color & 0x000000FF) * factor;
	*color = a | (r & 0x00FF0000) | (g & 0x0000FF00) | (b & 0x000000FF);
}

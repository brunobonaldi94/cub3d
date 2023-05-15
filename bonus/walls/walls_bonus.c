/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:52:18 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/15 20:08:48 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	draw_ceil(t_cubd *cub3d, int wall_top_pixel, int x)
{
	int	y;
	int	color;

	y = -1;
	color = rgb_to_hex(cub3d->map.ceiling_color);
	while (++y < wall_top_pixel)
	{
		if (x < (cub3d->game->window.width) * MINIMAP_SCALE
			&& y > (cub3d->game->window.height) * MINIMAP_SCALE)
			img_pix_put(&cub3d->img_game, x, y, color);
		else if (x > (cub3d->game->window.width - 1) * MINIMAP_SCALE)
			img_pix_put(&cub3d->img_game, x, y, color);
	}
}

void	draw_floor(t_cubd *cub3d, int wall_bottom_pixel, int x)
{
	int	y;
	int	color;

	y = wall_bottom_pixel;
	color = rgb_to_hex(cub3d->map.floor_color);
	while (++y < WINDOW_HEIGHT)
	{
		img_pix_put(&cub3d->img_game, x, y, color);
	}
}

void	draw_walls(t_cubd *cub3d, int x, t_wall *wall)
{
	int	y;

	y = wall->wall_top_pixel;
	wall->text_num = get_wall_facing(&cub3d->rays[x]);
	wall->text_offset_x = get_text_offset_x(&cub3d->rays[x]);
	while (y < wall->wall_bottom_pixel)
	{
		wall->dist_from_top = y + (wall->wall_height / 2) - (WINDOW_HEIGHT / 2);
		wall->text_offset_y = wall->dist_from_top
			* ((double) cub3d->textures
			[wall->text_num].height / wall->wall_height);
		wall->color = get_color_pixel(cub3d,
				wall->text_num, wall->text_offset_x, wall->text_offset_y);
		if (cub3d->rays[x].has_hit_vertical)
			color_intensity(&wall->color, 0.6);
		img_pix_put(&cub3d->img_game, x, y, wall->color);
		y++;
	}
}

void	render_3d_projected_walls(t_cubd *cub3d)
{
	t_wall	wall;
	int		x;

	x = -1;
	while (++x < NUM_RAYS)
	{
		wall.wall_height = (int) get_projected_wall_height(
				get_perp_dist(&cub3d->rays[x], cub3d->player),
				get_dis_proj_plane());
		wall.wall_top_pixel = get_wall_top_pixel(wall.wall_height);
		wall.wall_bottom_pixel = get_wall_bottom_pixel(wall.wall_height);
		draw_ceil(cub3d, wall.wall_top_pixel, x);
		draw_walls(cub3d, x, &wall);
		draw_floor(cub3d, wall.wall_bottom_pixel, x);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:52:18 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/08 18:59:50 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	get_perp_dist(t_ray *ray, t_player *player)
{
	return (ray->distance * cos(ray->ray_angle - player->rotation_angle));
}

double	get_dis_proj_plane(void)
{
	return ((WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2));
}

double	get_projected_wall_height(double perp_dist, double dist_project_plan)
{
	return ((TILE_SIZE / perp_dist) * dist_project_plan);
}

int	get_wall_top_pixel(int wall_strip_height)
{
	int	wall_top_pixel;

	wall_top_pixel = (WINDOW_HEIGHT / 2) - (wall_strip_height / 2);
	if (wall_top_pixel < 0)
		return (0);
	return (wall_top_pixel);
}

int	get_wall_bottom_pixel(int wall_strip_height)
{
	int	wall_bottom_pixel;

	wall_bottom_pixel = (WINDOW_HEIGHT / 2) + (wall_strip_height / 2);
	if (wall_bottom_pixel > WINDOW_HEIGHT)
		return (WINDOW_HEIGHT);
	return (wall_bottom_pixel);
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
		else if (x > (cub3d->game->window.width) * MINIMAP_SCALE)
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

int	get_text_offset_x(t_ray *ray)
{
	if (ray->has_hit_vertical)
		return ((int) ray->wall_hit_y % TILE_SIZE);
	return ((int) ray->wall_hit_x % TILE_SIZE);
}

/* int	get_wall_facing(t_ray *ray)
{
	if (ray->has_hit_vertical && is_ray_facing_right(ray->ray_angle))
		return (EA);
	else if (ray->has_hit_vertical && is_ray_facing_left(ray->ray_angle))
		return (WE);
	else if (!ray->has_hit_vertical && is_ray_facing_up(ray->ray_angle))
		return (NO);
	else  if (!ray->has_hit_vertical && is_ray_facing_right(ray->ray_angle))
		return (SO);
} */

void draw_wall(t_cubd *cub3d, int x, int wall_top_pixel, int wall_bottom_pixel)
{
	int	y;
	// int	dist_from_top;
	// int	text_offset_y;

	// y = -1;
	// while (++y < wall_top_y)
	// {
	// 	dist_from_top = y + (wall_height / 2) - (WINDOW_HEIGHT / 2)''
	// } */
	y = wall_top_pixel;
	while (y < wall_bottom_pixel)
	{
		img_pix_put(&cub3d->img_game, x, y++, RED_PIXEL);
	}
	
}

void	render_3D_projected_walls(t_cubd *cub3d)
{
	int	x;
	int	wall_strip_height;
	int	wall_top_pixel;
	int	wall_bottom_pixel;
	// int	text_offset_x;
	// int	text_num;
	// int	text_width;
	// int	text_height;

	x = -1;
	while (++x < NUM_RAYS)
	{
		wall_strip_height = (int) get_projected_wall_height(
				get_perp_dist(&cub3d->rays[x], cub3d->player),
				get_dis_proj_plane());
		wall_top_pixel = get_wall_top_pixel(wall_strip_height);
		wall_bottom_pixel = get_wall_bottom_pixel(wall_strip_height);
		draw_ceil(cub3d, wall_top_pixel, x);
		//text_offset_x = get_text_offset_x(&cub3d->rays[x]);
		//text_num = NO;
		draw_wall(cub3d, x, wall_top_pixel, wall_bottom_pixel);
		draw_floor(cub3d, wall_bottom_pixel, x);
	}
}
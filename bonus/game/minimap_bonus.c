/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 21:01:26 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/10 23:13:34 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	draw_wall_or_empty_minimap(t_cubd *cub3d, t_rectangle *rect,
				char map_char, t_cord cord)
{
	int	color_set;

	color_set = TRUE;
	if (map_char == WALL_CHAR)
		set_color_rect(rect, DARKGOLDENROD_PIXEL);
	else if (map_char == EMPTY_CHAR || map_char == SOUTH_PROP[0]
		|| map_char == NORTH_PROP[0] || map_char == EAST_PROP[0]
		|| map_char == WEST_PROP[0])
		set_color_rect(rect, SADDLE_BROW_PIXEL);
	else
		color_set = FALSE;
	if (!color_set)
		return ;
	rect->x = cord.x * TILE_SIZE * MINIMAP_SCALE;
	rect->y = cord.y * TILE_SIZE * MINIMAP_SCALE;
	render_rect(cub3d, rect);
}

int	render_minimap(t_cubd *cub3d)
{
	int			x;
	int			y;
	t_rectangle	rect;

	y = 0;
	rect.color = 0;
	rect.width = TILE_SIZE * MINIMAP_SCALE;
	rect.height = TILE_SIZE * MINIMAP_SCALE;
	while (y < cub3d->map.dimensions.rows)
	{
		x = 0;
		while (x < cub3d->map.dimensions.columns)
		{
			draw_wall_or_empty_minimap(cub3d, &rect, cub3d->game->map[y][x],
				(t_cord){x, y});
			x++;
		}
		y++;
	}
	return (TRUE);
}

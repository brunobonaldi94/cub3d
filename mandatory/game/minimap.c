#include "cub3D.h"

static int  set_wall_or_empty_color(t_rectangle *rect, char map_char)
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
	return (color_set);
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
			if (set_wall_or_empty_color(&rect, cub3d->game->map[y][x]))
			{
				rect.x = x * TILE_SIZE * MINIMAP_SCALE;
				rect.y = y * TILE_SIZE * MINIMAP_SCALE;
				render_rect(cub3d, &rect);
			}
			x++;
		}
		y++;
	}
	return (TRUE);
}

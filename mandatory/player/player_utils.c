#include "cub3D.h"

int	has_wall_at(char **map, double new_x, double new_y, t_cubd *cub3d)
{
	int	x;
	int	y;

	if (!is_inside_map(cub3d->game->window, new_x, new_y))
		return (TRUE);
	x = (int)floor((new_x / TILE_SIZE));
	y = (int)floor((new_y / TILE_SIZE));
	if (x >= cub3d->map.dimensions.columns - 1
		|| y >= cub3d->map.dimensions.rows - 1)
		return (TRUE);
	return (map[y][x] == WALL_CHAR);
}

int	is_inside_map(t_window window, double new_x, double new_y)
{
	return (new_x >= 0 && new_x <= window.width
		&& new_y >= 0 && new_y <= window.height);
}

void	normalize_angle(double *angle)
{
	*angle = remainder(*angle, TWO_PI);
	if (*angle < 0)
		*angle = TWO_PI + *angle;
}

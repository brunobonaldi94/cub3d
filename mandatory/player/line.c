#include "cub3D.h"

static int get_pixel(t_line *line)
{
	if (abs(line->delta_x) >= abs(line->delta_y))
		return (abs(line->delta_x));
	return (abs(line->delta_y));
}

int	draw_line(t_cubd *cub3d, t_line *line)
{
	double	increment_x;
	double	increment_y;

	line->delta_x = (line->end_x - line->begin_x);
	line->delta_y = (line->end_y - line->begin_y);
	line->pixels = get_pixel(line);
	increment_x = line->delta_x / (double) line->pixels;
	increment_y = line->delta_y / (double) line->pixels;
	line->pixel_x = line->begin_x;
	line->pixel_y = line->begin_y;
	while (line->pixels)
	{
		mlx_pixel_put(
			cub3d->mlx_ptr,
			cub3d->win_ptr,
			round(line->pixel_x),
			round(line->pixel_y),
			line->color);
		line->pixel_x += increment_x;
		line->pixel_y += increment_y;
		line->pixels--;
	}
	return (0);
}

#include "cub3D.h"

int draw_line(t_cubd *cub3d, t_line *line)
{
    line->delta_x = line->end_x - line->begin_x; 
    line->delta_y = line->end_y - line->begin_y; 

    line->pixels = sqrt((line->delta_x * line->delta_y) + (line->delta_y * line->delta_y));
    line->pixel_x = line->begin_x;
    line->pixel_y = line->begin_y;

    line->delta_x /= line->pixels; 
    line->delta_y /= line->pixels;
    while (line->pixels)
    {
        mlx_pixel_put(cub3d->mlx_ptr, cub3d->win_ptr, line->pixel_x, line->pixel_y, line->color);
        line->pixel_x += line->delta_x;
        line->pixel_y += line->delta_y;
        line->pixels--;
    }
    return (0);
}

#include "cub3D.h"

typedef struct s_line
{
    int     begin_x;
    int     begin_y;
    int     end_x;
    int     end_y;
    int     color;
    int     pixels;
    float   delta_x;
    float   delta_y;
    float   pixel_x;
    float   pixel_y;
}   t_line;


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

/* int main()
{
    t_cubd cub3d;
    t_line line;
    cub3d.mlx_ptr = mlx_init();
    cub3d.win_ptr = mlx_new_window(cub3d.mlx_ptr, 640, 360, "Tutorial Draw Line");

    line.begin_x = 640;
    line.begin_y = 360;
    line.end_x = 0;
    line.end_y = 0;
    line.color = 0xFFFFFF;
    draw_line(&cub3d, &line);
    mlx_loop(cub3d.mlx_ptr);
} */

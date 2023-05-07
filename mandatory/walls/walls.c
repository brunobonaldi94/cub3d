#include "cub3D.h"

double  get_perp_dist(t_ray *ray, t_player *player)
{
    return (ray->distance * cos(ray->ray_angle - player->rotation_angle));
}

double  get_dis_proj_plane(void)
{
    return ((WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2));
}

double  get_projected_wall_height(double perp_dist, double dist_project_plan)
{
    return ((TILE_SIZE / perp_dist) * dist_project_plan);
}

int get_wall_top_pixel(int wall_strip_height)
{
    int wall_top_pixel;

    wall_top_pixel = (WINDOW_HEIGHT / 2) - (wall_strip_height / 2);
    if (wall_top_pixel < 0)
        return (0);
    return (wall_top_pixel);
}

int get_wall_bottom_pixel(int wall_strip_height)
{
    int wall_bottom_pixel;

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


void    draw_ceil(t_cubd *cub3d, int wall_top_pixel, int x)
{
    int y;

    y = -1;
    while (++y < wall_top_pixel)
    {
        pixel_put(&cub3d->img_game, x, y, 0xFF444444);
        //mlx_pixel_put(cub3d->mlx_ptr, cub3d->win_ptr, x, y, 0xFF444444);
    }
}

void    draw_floor(t_cubd *cub3d, int wall_bottom_pixel, int x)
{

    int y;

    y = wall_bottom_pixel;
    while (++y < WINDOW_HEIGHT)
    {
        pixel_put(&cub3d->img_game, x, y, 0xFF888888);
        //mlx_pixel_put(cub3d->mlx_ptr, cub3d->win_ptr, x, y, 0xFF888888);
    }
}


void    render_3D_projected_walls(t_cubd *cub3d)
{
    int     x;    
    int wall_strip_height;
    int wall_top_pixel;
    int wall_bottom_pixel;

    x = -1;
    while (++x < NUM_RAYS)
    {
        wall_strip_height = (int) get_projected_wall_height(
            get_perp_dist(&cub3d->rays[x], cub3d->player),
            get_dis_proj_plane());
        wall_top_pixel = get_wall_top_pixel(wall_strip_height);
        wall_bottom_pixel = get_wall_bottom_pixel(wall_strip_height);
        draw_ceil(cub3d, wall_top_pixel, x);
        draw_floor(cub3d, wall_bottom_pixel, x);
    }
}

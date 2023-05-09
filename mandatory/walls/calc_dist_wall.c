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

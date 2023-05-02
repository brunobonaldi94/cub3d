#include "cub3D.h"

// Find the y-coordinate of the closest horizontal grid intersection
double	get_y_intercept(t_player *player)
{
	return (floor(player->y / TILE_SIZE) * TILE_SIZE);
}
// Find the x-coordinate of the closest horizontal grid intersection
double get_x_intercept(t_player *player, double angle, double y_intercept)
{
	double result;

	result = player->x + (y_intercept - player->y) * tan(angle); 
	return (result);
}

void	increment_y_intercept(double *y_intercept, double angle)
{
	if (is_ray_facing_down(angle))
		*y_intercept += TILE_SIZE;
}


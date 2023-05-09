#include "cub3D.h"

int	get_text_offset_x(t_ray *ray)
{
	if (ray->has_hit_vertical)
		return ((int) ray->wall_hit_y % TILE_SIZE);
	return ((int) ray->wall_hit_x % TILE_SIZE);
}

int	get_wall_facing(t_ray *ray)
{
	if (ray->has_hit_vertical && is_ray_facing_right(ray->ray_angle))
		return (EA);
	else if (ray->has_hit_vertical && is_ray_facing_left(ray->ray_angle))
		return (WE);
	else if (!ray->has_hit_vertical && is_ray_facing_up(ray->ray_angle))
		return (NO);
	else  if (!ray->has_hit_vertical && is_ray_facing_right(ray->ray_angle))
		return (SO);
	return (0);
}

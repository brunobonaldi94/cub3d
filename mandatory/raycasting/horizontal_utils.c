#include "cub3D.h"

void	set_horz_intersects(t_cubd *cub3d, t_intersection *intersec,
			double ray_angle)
{
	intersec->y_intercept = get_y_horizontal_intercept(cub3d->player);
	increment_y_horizontal_intercept(&intersec->y_intercept, ray_angle);
	intersec->x_intercept = get_x_horizontal_intercept(
			cub3d->player,
			ray_angle,
			intersec->y_intercept);
}

void	set_horz_steps(t_intersection *intersec, double ray_angle)
{
	intersec->y_step = TILE_SIZE;
	invert_y_horizontal_step(&intersec->y_step, ray_angle);
	intersec->x_step = TILE_SIZE / tan(ray_angle);
	invert_x_horizontal_step(&intersec->x_step, ray_angle);
}

void	horizontal_intersection(t_cubd *cub3d, t_intersection *intersec, double ray_angle)
{
	set_horz_intersects(cub3d, intersec, ray_angle);
	set_horz_steps(intersec, ray_angle);
}

void	set_rays_horz(t_cubd *cub3d, t_intersection *intersec, int column_id, double angle)
{
	cub3d->rays[column_id].distance = intersec->distance;
	cub3d->rays[column_id].wall_hit_x = intersec->wall_hit_x;
	cub3d->rays[column_id].wall_hit_y = intersec->wall_hit_y;
	cub3d->rays[column_id].ray_angle = angle;
	cub3d->rays[column_id].has_hit_vertical = FALSE;
}

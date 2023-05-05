#include "cub3D.h"

void	set_vert_intersects(t_cubd *cub3d, t_intersection *intersec,
			double ray_angle)
{
	intersec->x_intercept = get_x_vertical_intercept(cub3d->player);
	increment_x_vertical_intercept(&intersec->y_intercept, ray_angle);
	intersec->y_intercept = get_y_vertical_intercept(
			cub3d->player,
			ray_angle,
			intersec->x_intercept);
}

void	set_vertical_steps(t_intersection *intersec, double ray_angle)
{
	intersec->x_step = TILE_SIZE;
	invert_x_vertical_step(&intersec->x_step, ray_angle);
	intersec->y_step = TILE_SIZE * tan(ray_angle);
	invert_y_vertical_step(&intersec->y_step, ray_angle);
}

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

void	increment_steps(t_intersection *intersec)
{
	intersec->next_x += intersec->x_step;
	intersec->next_y += intersec->y_step;
}

void	set_found_wall_hit(t_intersection *intersec)
{
	intersec->wall_hit_x = intersec->next_x;
	intersec->wall_hit_y = intersec->next_y;
}

void	set_next_start_position(t_intersection *intersec)
{
	intersec->next_x = intersec->x_intercept;
	intersec->next_y = intersec->y_intercept;
}

void	horizontal_intersection(t_cubd *cub3d, t_intersection *intersec, double ray_angle)
{
	set_horz_intersects(cub3d, intersec, ray_angle);
	set_horz_steps(intersec, ray_angle);
}

void	vertical_intersection(t_cubd *cub3d, t_intersection *intersec, double ray_angle)
{
	set_vert_intersects(cub3d, intersec, ray_angle);
	set_vertical_steps(intersec, ray_angle);
}


void	calculate_wall_hit(t_cubd *cub3d, t_intersection *intersec)
{
	set_next_start_position(intersec);
	intersec->distance = INT_MAX;
	while (is_inside_map(cub3d->game->window, intersec->next_x, intersec->next_y))
	{
		if (has_wall_at(cub3d->game->map, intersec->next_x, intersec->next_y, cub3d))
		{
			set_found_wall_hit(intersec);
			intersec->distance = calculate_distance_between_points(
					cub3d->player->x,
					cub3d->player->y,
					intersec->wall_hit_x,
					intersec->wall_hit_y
					);
			break ;
		}
		else
			increment_steps(intersec);
	}
}

void cast_ray(t_cubd *cub3d, double ray_angle, int column_id)
{
	t_intersection	*intersec_horz;
	t_intersection	*intersec_vert;

	(void) column_id;
	intersec_horz = malloc(sizeof(t_intersection));
	intersec_vert = malloc(sizeof(t_intersection));
	normalize_angle(&ray_angle);
	horizontal_intersection(cub3d, intersec_horz, ray_angle);
	calculate_wall_hit(cub3d, intersec_horz);
	vertical_intersection(cub3d, intersec_vert, ray_angle);
	calculate_wall_hit(cub3d, intersec_vert);
	if (intersec_horz->distance <= intersec_vert->distance)
		draw_ray(cub3d, intersec_horz->wall_hit_x, intersec_horz->wall_hit_y, RED_PIXEL);
	else
		draw_ray(cub3d, intersec_vert->wall_hit_x, intersec_vert->wall_hit_y, YELLOW_PIXEL);
	ft_free_ptr((void **)&intersec_horz);
	ft_free_ptr((void **)&intersec_vert);

}

void	cast_all_rays(t_cubd *cub3d, t_player *player, int color)
{
	(void)color;
	double	ray_angle;
	int		column_id;

	ray_angle = player->rotation_angle - FOV_ANGLE / 2;
	column_id = 0;
	while (column_id < NUM_RAYS)
	{
		cast_ray(cub3d, ray_angle, column_id);
		ray_angle += FOV_ANGLE / NUM_RAYS;
		column_id++;
	}
}


/*
	Distance to Wall Hit
	1. The best way is to check for horizontal and vertical
		intersections separately.
	2. When there is a wall on either a vertical or a 
		horizontal intersection, the checking stops.
	3. The distance to both horizontol and vertical intersection
		points is then compared, and we select the closest one.
	

	Horizontal intersections
	1.  Find coordinate of the first horizontal intersection (Point A)
	2.  Find ystep
	3.  Find xstep
	4.  Convert intersection point (x, y) into map index[i,j]
		-> if (intersection hits a wall)
				then: store horizontal hit distance
			else
				find next horizontal intersection
*/
/*
	Notes:
	Distance between rays: 60 (degrees / FOV) / 320 (rays)

	Steps:
	1. Subtract 30 degrees from the player rotation angle (FOV/2)
	2. Start at column 0
	3. While (column < 320):
		* Cast a ray
		* Trace the ray until it intersects with a wall (map[i][j] == 1)
		* Record the intersection (x,y) and the distance (ray length)
		* Add the angle increment so the ray moves to the right
			 -> ray_angle += 60/320
		*

*/

/*
	Vertical Intersections
	1.	Find coordinate of the first vertical intersection (point A)
	2.	Find xstep
	3.	Find ystep
	4.	Convert intersections point (x, y) into map[i,j]
		-> if (intersection hits a wall)
				then: store vertical hit distance
			else
				find next vertical intersection
*/

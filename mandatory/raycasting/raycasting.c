#include "cub3D.h"

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


void cast_ray(t_cubd *cub3d, double ray_angle, int column_id)
{
	(void) column_id;
	double	x_intercept;
	double	y_intercept;
	double	x_step;
	double	y_step;
	double	next_horz_x;
	double	next_horz_y;
	double	wall_hit_x;
	double	wall_hit_y;

	normalize_angle(&ray_angle);

	y_intercept = get_y_horizontal_intercept(cub3d->player);
	increment_y_horizontal_intercept(&y_intercept, ray_angle);

	x_intercept = get_x_horizontal_intercept(cub3d->player, ray_angle, y_intercept);
    
	y_step = TILE_SIZE;
	invert_y_horizontal_step(&y_step, ray_angle);

	x_step = TILE_SIZE;
	invert_x_horizontal_step(&x_step, ray_angle);

	next_horz_x = x_intercept;
	next_horz_y = y_intercept;

	while (is_inside_map(cub3d->game->window, next_horz_x, next_horz_y))
	{
		if (has_wall_at(cub3d->game->map, next_horz_x, next_horz_y, cub3d))
		{
			wall_hit_x = next_horz_x;
			wall_hit_y = next_horz_y;

			t_line *line = malloc(sizeof(t_line));
			line->begin_x = MINIMAP_SCALE * cub3d->player->x;
			line->begin_y = MINIMAP_SCALE * cub3d->player->y;
			line->end_x = MINIMAP_SCALE * wall_hit_x;
			line->end_y = MINIMAP_SCALE * wall_hit_y;
			line->color = RED_PIXEL;
    		draw_line(cub3d, line);
			break;
		}
		else
		{
			next_horz_x += x_step;
			next_horz_y += y_step;
		}
	}

}

//test render rays

void    render_ray(t_cubd *cub3d, t_player *player, double ray_angle, int color)
{
	t_line *line = malloc(sizeof(t_line));
	line->begin_x = MINIMAP_SCALE * player->x;
	line->begin_y = MINIMAP_SCALE * player->y;
	line->end_x = MINIMAP_SCALE * (player->x + cos(ray_angle) * RAY_LENGHT);
	line->end_y = MINIMAP_SCALE * (player->y + sin(ray_angle) * RAY_LENGHT);
	line->color = color;
	draw_line(cub3d, line);
}
void    cast_all_rays(t_cubd *cub3d, t_player *player, int color)
{
	(void)color;
	double	ray_angle;
	int		column_id;

	ray_angle = player->rotation_angle - FOV_ANGLE / 2;
	column_id = 0;
	while (column_id < 1)
	{
		//render_ray(cub3d, cub3d->player, ray_angle, color);
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

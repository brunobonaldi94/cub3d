#include "cub3D.h"

void	set_vert_intersects(t_cubd *cub3d, t_intersection *intersec,
			double ray_angle)
{
	intersec->x_intercept = get_x_vertical_intercept(cub3d->player);
	increment_x_vertical_intercept(&intersec->x_intercept, ray_angle);
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

void	set_to_check(t_intersection *intersec, double angle, int is_horz)
{
	intersec->x_to_check = intersec->next_x;
	intersec->y_to_check = intersec->next_y;

	if (is_horz)
	{
		if (is_ray_facing_up(angle))
			intersec->y_to_check -= 1;
	}
	else
	{
		if (is_ray_facing_left(angle))
			intersec->x_to_check -= 1;
	}
}

void	calculate_wall_hit(t_cubd *cub3d, t_intersection *intersec, double ray_angle, int is_horz)
{
	set_next_start_position(intersec);
	intersec->distance = INT_MAX;
	while (is_inside_map(cub3d->game->window, intersec->next_x, intersec->next_y))
	{
		set_to_check(intersec, ray_angle, is_horz);
		if (has_wall_at(cub3d->game->map, intersec->x_to_check, intersec->y_to_check, cub3d))
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

void	set_rays_horz(t_cubd *cub3d, t_intersection *intersec, int column_id, double angle)
{
	cub3d->rays[column_id].distance = intersec->distance;
	cub3d->rays[column_id].wall_hit_x = intersec->wall_hit_x;
	cub3d->rays[column_id].wall_hit_y = intersec->wall_hit_y;
	cub3d->rays[column_id].ray_angle = angle;
	cub3d->rays[column_id].has_hit_vertical = FALSE;
}

void	set_rays_vert(t_cubd *cub3d, t_intersection *intersec, int column_id, double angle)
{
	cub3d->rays[column_id].distance = intersec->distance;
	cub3d->rays[column_id].wall_hit_x = intersec->wall_hit_x;
	cub3d->rays[column_id].wall_hit_y = intersec->wall_hit_y;	
	cub3d->rays[column_id].ray_angle = angle;
	cub3d->rays[column_id].has_hit_vertical = TRUE;
}

void	cast_ray(t_cubd *cub3d, double ray_angle, int column_id)
{
	t_intersection	*intersec_horz;
	t_intersection	*intersec_vert;

	(void) column_id;
	intersec_horz = malloc(sizeof(t_intersection));
	intersec_vert = malloc(sizeof(t_intersection));
	normalize_angle(&ray_angle);
	horizontal_intersection(cub3d, intersec_horz, ray_angle);
	calculate_wall_hit(cub3d, intersec_horz, ray_angle, TRUE);
	vertical_intersection(cub3d, intersec_vert, ray_angle);
	calculate_wall_hit(cub3d, intersec_vert, ray_angle, FALSE);
	if (intersec_horz->distance <= intersec_vert->distance)
		set_rays_horz(cub3d, intersec_horz, column_id, ray_angle);
	else
		set_rays_vert(cub3d, intersec_vert, column_id, ray_angle);
	ft_free_ptr((void **)&intersec_horz);
	ft_free_ptr((void **)&intersec_vert);

}

void	render_rays(t_cubd *cub3d) 
{
	int	i;

	i = 0;
	while (i < NUM_RAYS)
	{
		draw_ray(cub3d,
			cub3d->rays[i].wall_hit_x,
			cub3d->rays[i].wall_hit_y,
			NAVAJOWHITE_PIXEL);
		i += 50;
	}
}

void	cast_all_rays(t_cubd *cub3d, t_player *player)
{
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

#include "cub3D.h"

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

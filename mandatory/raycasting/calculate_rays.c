/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_rays.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:35:19 by sjhony-x          #+#    #+#             */
/*   Updated: 2023/05/09 16:35:27 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	increment_steps(t_intersection *intersec)
{
	intersec->next_x += intersec->x_step;
	intersec->next_y += intersec->y_step;
}

static void	set_found_wall_hit(t_intersection *intersec)
{
	intersec->wall_hit_x = intersec->next_x;
	intersec->wall_hit_y = intersec->next_y;
}

static void	set_next_start_position(t_intersection *intersec)
{
	intersec->next_x = intersec->x_intercept;
	intersec->next_y = intersec->y_intercept;
}

static void	set_to_check(t_intersection *intersec, double angle, int is_horz)
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

void	calculate_wall_hit(t_cubd *cub3d, t_intersection *intersec,
	double ray_angle, int is_horz)
{
	set_next_start_position(intersec);
	intersec->distance = INT_MAX;
	while (is_inside_map(cub3d->game->window,
			intersec->next_x, intersec->next_y))
	{
		set_to_check(intersec, ray_angle, is_horz);
		if (has_wall_at(cub3d->game->map,
				intersec->x_to_check, intersec->y_to_check, cub3d))
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

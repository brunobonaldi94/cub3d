/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:35:27 by sjhony-x          #+#    #+#             */
/*   Updated: 2023/05/10 23:15:04 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	cast_ray(t_cubd *cub3d, double ray_angle, int column_id)
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

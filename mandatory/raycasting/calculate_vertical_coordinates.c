/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_vertical_coordinates .c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:36:30 by sjhony-x          #+#    #+#             */
/*   Updated: 2023/05/09 20:46:57 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	get_y_vertical_intercept(t_player *player, double angle,
			double x_intercept)
{
	return (player->y + (x_intercept - player->x) * tan(angle));
}

double	get_x_vertical_intercept(t_player *player)
{
	return (floor(player->x / TILE_SIZE) * TILE_SIZE);
}

void	increment_x_vertical_intercept(double *x_intercept, double angle)
{
	if (is_ray_facing_right(angle))
		*x_intercept += TILE_SIZE;
}

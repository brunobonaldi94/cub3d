/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_horizontal_coordinates_bonus.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:36:30 by sjhony-x          #+#    #+#             */
/*   Updated: 2023/05/10 23:15:44 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

double	get_y_horizontal_intercept(t_player *player)
{
	return (floor(player->y / TILE_SIZE) * TILE_SIZE);
}

double	get_x_horizontal_intercept(t_player *player, double angle,
	double y_intercept)
{
	return (player->x + (y_intercept - player->y) / tan(angle));
}

void	increment_y_horizontal_intercept(double *y_intercept, double angle)
{
	if (is_ray_facing_down(angle))
		*y_intercept += TILE_SIZE;
}

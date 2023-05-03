/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_coordinates.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 21:26:00 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/02 21:50:33 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	get_y_horizontal_intercept(t_player *player)
{
	return (floor(player->y / TILE_SIZE) * TILE_SIZE);
}

double	get_y_vertical_intercept(t_player *player, double angle,
			double y_intercept)
{
	return (player->y + (y_intercept - player->x) * tan(angle));
}

double	get_x_horizontal_intercept(t_player *player, double angle,
	double y_intercept)
{
	return (player->x + (y_intercept - player->y) / tan(angle));
}

double	get_x_vertical_intercept(t_player *player)
{
	return (floor(player->x / TILE_SIZE) * TILE_SIZE);
}

void	increment_y_horizontal_intercept(double *y_intercept, double angle)
{
	if (is_ray_facing_down(angle))
		*y_intercept += TILE_SIZE;
}

void	increment_x_vertical_intercept(double *x_intercept, double angle)
{
	if (is_ray_facing_right(angle))
		*x_intercept += TILE_SIZE;
}

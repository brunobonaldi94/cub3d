/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_steps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 21:50:40 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/02 22:15:17 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	invert_y_horizontal_step(double *y_step, double angle)
{
	if (is_ray_facing_up(angle))
		*y_step *= -1;
}

void	invert_y_vertical_step(double *y_step, double angle)
{
	if ((is_ray_facing_up(angle) && *y_step > 0)
		|| (is_ray_facing_down(angle) && *y_step < 0))
		*y_step *= -1;
}

void	invert_x_horizontal_step(double *x_step, double angle)
{
	if ((is_ray_facing_left(angle) && *x_step > 0)
		|| ( is_ray_facing_right(angle) && *x_step < 0))
		*x_step *= -1;
}

void	invert_x_vertical_step(double *x_step, double angle)
{
	if (is_ray_facing_left(angle))
		*x_step *= -1;
}

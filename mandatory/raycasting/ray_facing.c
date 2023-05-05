/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_facing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 20:40:55 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/04 20:41:20 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_ray_facing_down(double angle)
{
	return (angle > 0 && angle < PI);
}

int	is_ray_facing_up(double angle)
{
	return (!is_ray_facing_down(angle));
}

int	is_ray_facing_right(double angle)
{
	return (angle < 0.5 * PI || angle > 1.5 * PI);
}

int	is_ray_facing_left(double angle)
{
	return (!is_ray_facing_right(angle));
}

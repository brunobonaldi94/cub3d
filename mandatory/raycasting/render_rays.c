/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:35:38 by sjhony-x          #+#    #+#             */
/*   Updated: 2023/05/09 16:35:38 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

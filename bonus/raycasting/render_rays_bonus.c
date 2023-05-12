/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rays_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:35:38 by sjhony-x          #+#    #+#             */
/*   Updated: 2023/05/10 23:15:44 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

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

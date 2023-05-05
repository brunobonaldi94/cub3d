/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 20:41:27 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/04 20:41:30 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_line	*draw_ray(t_cubd *cub3d, double end_x, double end_y, int color)
{
	t_line	*line;

	line = malloc(sizeof(t_line));
	if (!line)
		return (NULL);
	line->begin_x = MINIMAP_SCALE * cub3d->player->x;
	line->begin_y = MINIMAP_SCALE * cub3d->player->y;
	line->end_x = MINIMAP_SCALE * end_x;
	line->end_y = MINIMAP_SCALE * end_y;
	line->color = color;
	draw_line(cub3d, line);
	ft_free_ptr((void **)&line);
	return (line);
}

double	calculate_distance_between_points(double x1, double y1,
			double x2, double y2) {
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

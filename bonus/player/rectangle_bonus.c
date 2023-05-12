/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:00:58 by sjhony-x          #+#    #+#             */
/*   Updated: 2023/05/10 23:15:44 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	draw_rect(t_img *img, t_rectangle *rect)
{
	int	i;
	int	j;

	i = rect->y;
	while (i < rect->y + rect->height)
	{
		j = rect->x;
		while (j < rect->x + rect->width)
			img_pix_put(img, j++, i, rect->color);
		i++;
	}
	return (0);
}

t_rectangle	*create_rect(int x, int y, int width, int height)
{
	t_rectangle	*rect;

	rect = malloc(sizeof(t_rectangle));
	rect->x = x;
	rect->y = y;
	rect->width = width;
	rect->height = height;
	return (rect);
}

void	set_color_rect(t_rectangle *rect, int color)
{
	rect->color = color;
}

int	render_rect(t_cubd *cub3d, t_rectangle *rect)
{
	draw_rect(&cub3d->img_game, rect);
	return (0);
}

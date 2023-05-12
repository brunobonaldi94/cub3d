/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:56:55 by sjhony-x          #+#    #+#             */
/*   Updated: 2023/05/10 23:15:44 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	num_rows(char **map)
{
	int	rows;

	rows = 0;
	while (map[rows])
		rows++;
	return (rows);
}

t_window	get_window(t_map *map)
{
	t_window	window;

	window.width = map->dimensions.columns * TILE_SIZE;
	window.height = map->dimensions.rows * TILE_SIZE;
	return (window);
}

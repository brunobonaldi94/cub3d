/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 06:57:51 by sjhony-x          #+#    #+#             */
/*   Updated: 2023/04/30 14:58:57 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:56:55 by sjhony-x          #+#    #+#             */
/*   Updated: 2023/05/09 15:57:01 by sjhony-x         ###   ########.fr       */
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

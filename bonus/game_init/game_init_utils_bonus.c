/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 22:16:02 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/10 23:13:34 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	init_colors(t_color *color);

void	init_map(t_map	*map)
{
	map->map_list = NULL;
	map->dimensions.columns = 0;
	map->dimensions.rows = 0;
	map->dimensions.col_offset = 0;
	map->map_matrix = NULL;
	map->map_file.name = NULL;
	map->map_file.fd = UNINITIALIZED_FD;
	map->so_file = NULL;
	map->no_file = NULL;
	map->we_file = NULL;
	map->ea_file = NULL;
	map->found_player = FALSE;
	init_colors(&map->floor_color);
	init_colors(&map->ceiling_color);
}

void	init_colors(t_color *color)
{
	color->color_str = NULL;
	color->r = -1;
	color->g = -1;
	color->b = -1;
	color->alpha = 1;
}

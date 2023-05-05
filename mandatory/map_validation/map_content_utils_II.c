/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content_utils_II.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:49:59 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/04 20:36:53 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_starting_rotation_angle(t_player *player)
{
	if (player->player_char == 'N')
		player->rotation_angle = PI * 1.5;
	else if (player->player_char == 'S')
		player->rotation_angle = PI * 0.5;
	else if (player->player_char == 'W')
		player->rotation_angle = PI;
	else if (player->player_char == 'E')
		player->rotation_angle = PI * 2;
}

void	set_player_position(char **map, t_player *player, t_cord cord)
{
	player->player_char = map[cord.y][cord.x];
	player->x = (double)(cord.x * TILE_SIZE);
	player->y = (double)(cord.y * TILE_SIZE);
	set_starting_rotation_angle(player);
}

int	is_player_inside_map(t_cord cord)
{
	return (cord.x >= 0 && cord.y >= 0);
}

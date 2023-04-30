/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content_utils_II.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:49:59 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/04/30 14:06:35 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	is_player_insid_map(t_cord cord);
void	set_player_position(t_player *player, t_cord cord);

void	set_player_position(t_player *player, t_cord cord)
{
	player->x = (double)cord.x * TILE_SIZE;
	player->y = (double)cord.y * TILE_SIZE;
}

int	is_player_inside_map(t_cord cord)
{
	return (cord.x >= 0 && cord.x >= 0);
}

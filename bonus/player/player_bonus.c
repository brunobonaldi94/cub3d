/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:58:12 by sjhony-x          #+#    #+#             */
/*   Updated: 2023/05/15 19:42:02 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	init_player(t_cubd *cub3d)
{
	cub3d->player = (t_player *)malloc(sizeof(t_player));
	cub3d->player->x = cub3d->game->window.width / 2;
	cub3d->player->y = cub3d->game->window.height / 2;
	cub3d->player->width = 1;
	cub3d->player->height = 1;
	cub3d->player->turn_direction = 0;
	cub3d->player->walk_direction = 0;
	cub3d->player->walk_side_direction = 0;
	cub3d->player->rotation_angle = (PI / 2);
	cub3d->player->walk_speed = 20;
	cub3d->player->turn_speed = 10 * (PI / 180);
}

t_coordinates	get_new_pos(t_cubd *cub3d, double move_step, double side_step)
{
	t_coordinates	coords;

	coords.x = cub3d->player->x
		+ (cos(cub3d->player->rotation_angle) * move_step)
		+ (cos(cub3d->player->rotation_angle + PI / 2) * side_step);
	coords.y = cub3d->player->y
		+ sin(cub3d->player->rotation_angle) * move_step
		+ (sin(cub3d->player->rotation_angle + PI / 2) * side_step);
	return (coords);
}

void	move_player(t_cubd *cub3d)

{
	double			move_step;
	double			side_step;
	t_coordinates	coords;

	if (cub3d->player->turn_direction)
	{
		cub3d->player->rotation_angle += cub3d->player->turn_direction
			* cub3d->player->turn_speed;
		normalize_angle(&cub3d->player->rotation_angle);
	}
	if (cub3d->player->walk_direction || cub3d->player->walk_side_direction)
	{
		move_step = cub3d->player->walk_direction * cub3d->player->walk_speed;
		side_step = cub3d->player->walk_side_direction
			* cub3d->player->walk_speed;
		coords.x = get_new_pos(cub3d, move_step, side_step).x;
		coords.y = get_new_pos(cub3d, move_step, side_step).y;
		if (has_wall_at(cub3d->game->map, coords.x, coords.y, cub3d)
			|| coords.x <= (double) TILE_SIZE)
			return ;
		cub3d->player->x = coords.x;
		cub3d->player->y = coords.y;
	}
}

int	key_down(int key, t_cubd *cub3d)
{
	if (key == KEY_SCAPE)
		game_exit(cub3d);
	else if (key == KEY_W)
		cub3d->player->walk_direction = +1;
	else if (key == KEY_S)
		cub3d->player->walk_direction = -1;
	else if (key == KEY_RIGHT)
		cub3d->player->turn_direction = +1;
	else if (key == KEY_LEFT)
		cub3d->player->turn_direction = -1;
	else if (key == KEY_A)
		cub3d->player->walk_side_direction = -1;
	else if (key == KEY_D)
		cub3d->player->walk_side_direction = +1;
	move_player(cub3d);
	game_render(cub3d);
	return (0);
}

int	key_up(int key, t_cubd *cub3d)
{
	if (key == KEY_W)
		cub3d->player->walk_direction = 0;
	else if (key == KEY_S)
		cub3d->player->walk_direction = 0;
	else if (key == KEY_RIGHT)
		cub3d->player->turn_direction = 0;
	else if (key == KEY_LEFT)
		cub3d->player->turn_direction = 0;
	else if (key == KEY_A)
		cub3d->player->walk_side_direction = 0;
	else if (key == KEY_D)
		cub3d->player->walk_side_direction = 0;
	return (0);
}

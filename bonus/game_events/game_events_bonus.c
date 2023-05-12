/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:30:19 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/10 23:13:34 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	deal_key_press(int key, t_cubd *cub3D);

void	game_loop_events(t_cubd *cub3D)
{
	mlx_expose_hook(cub3D->win_ptr, &game_render, cub3D);
	mlx_hook(cub3D->win_ptr, KEY_UP_EVENT, 1l << 1, &key_up, cub3D);
	mlx_hook(cub3D->win_ptr, KEY_DOWN_EVENT, 1l << 0, &key_down, cub3D);
	mlx_hook(cub3D->win_ptr, DESTROY_NOTIFY_EVENT, 1L << 17, &game_exit,
		cub3D);
}

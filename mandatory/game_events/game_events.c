/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:30:19 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/04/21 16:01:59 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	deal_key_press(int key, t_cub3D *cub3D);

void	game_loop_events(t_cub3D *cub3D)
{
	mlx_hook(cub3D->win_ptr, KEY_PRESS_EVENT, (1L << 0), &deal_key_press,
		cub3D);
	mlx_hook(cub3D->win_ptr, DESTROY_NOTIFY_EVENT, (1L << 17), &game_exit,
		cub3D);
}

int	deal_key_press(int key, t_cub3D *cub3D)
{
	if (key == KEY_SCAPE)
		game_exit(cub3D);
	return (SUCCESS_CODE);
}

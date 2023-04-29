/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:41:30 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/04/23 15:42:19 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char *argv[])
{
	t_cubd	cubd;
	t_game game;

	cubd.game = &game;
	if (!has_valid_args(argc))
		exit_with_message(ERROR_CODE, INVALID_ARGS_MESSAGE);
	init_game(&cubd, argv);
	game_loop_events(&cubd);
	mlx_loop(cubd.mlx_ptr);
	return (SUCCESS_CODE);
}

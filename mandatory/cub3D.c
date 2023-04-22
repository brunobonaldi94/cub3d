/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:41:30 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/04/22 17:51:56 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char *argv[])
{
	t_cubd	cubd;

	cubd.map.dimensions.columns = 20;
	cubd.map.dimensions.rows = 20;
	if (!has_valid_args(argc))
		exit_with_message(ERROR_CODE, INVALID_ARGS_MESSAGE);
	init_game(&cubd, argv);
	game_loop_events(&cubd);
	mlx_loop(cubd.mlx_ptr);
	return (SUCCESS_CODE);
}

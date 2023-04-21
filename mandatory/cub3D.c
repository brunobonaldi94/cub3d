/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:41:30 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/04/21 15:59:48 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char *argv[])
{
	t_cub3D	cub3D;

	cub3D.map.columns = 20;
	cub3D.map.rows = 20;
	if (!has_valid_args(argc))
		exit_with_message(ERROR_CODE, INVALID_ARGS_MESSAGE);
	init_game(&cub3D, argv);
	game_loop_events(&cub3D);
	mlx_loop(cub3D.mlx_ptr);
	return (SUCCESS_CODE);
}

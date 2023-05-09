/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_minilibx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 20:12:10 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/08 22:32:22 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	game_render(t_cubd *cub3D)
{
	init_textures(cub3D);
	create_image(cub3D, &cub3D->img_game, WINDOW_WIDTH, WINDOW_HEIGHT);
	cast_all_rays(cub3D, cub3D->player);
	render_3D_projected_walls(cub3D);
	render_minimap(cub3D);
	render_player(cub3D, cub3D->player);
	render_rays(cub3D);
	render_image_to_window(cub3D, &cub3D->img_game, 0, 0);
	mlx_destroy_image(cub3D->mlx_ptr, cub3D->img_game.mlx_img);
	destroy_textures(cub3D);
	return (TRUE);
}

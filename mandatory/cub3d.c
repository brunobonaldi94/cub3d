/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:41:30 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/04/20 22:19:41 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(void)
{
	t_cub3d	cub3d;

	cub3d.map.columns = 20;
	cub3d.map.rows = 20;
	init_mlx(&cub3d);
	mlx_loop(cub3d.mlx_ptr);
	return (0);
}

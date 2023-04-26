/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:36:25 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/04/25 20:41:22 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_map(t_cubd *cub3D)
{
	int	index;

	if (!DEBUG)
		return ;
	index = 0;
	ft_printf("map:\n");
	while (index < cub3D->map.dimensions.rows)
	{
		ft_printf("%s\n", cub3D->map.map_matrix[index]);
		index++;
	}
	ft_printf("map rows :%d\nmap cols: %d\nceiling_color: %s\nfloor_color: %s\
		\nno_file: %s\nso_file: %s\nea_file: %s\nwe_file: %s\n",
		cub3D->map.dimensions.rows,
		cub3D->map.dimensions.columns,
		cub3D->map.ceiling_color.color_str,
		cub3D->map.floor_color.color_str,
		cub3D->map.no_file,
		cub3D->map.so_file,
		cub3D->map.ea_file,
		cub3D->map.we_file);
}

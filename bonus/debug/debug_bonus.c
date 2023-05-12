/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:36:25 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/10 23:13:03 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	print_map(t_cubd *cub3D)
{
	int	index;

	if (!DEBUG)
		return ;
	index = 0;
	ft_printf(YELLOW"NO: %s\nSO: %s\nEA: %s\nWE: %s\n"RESET,
		cub3D->map.no_file,
		cub3D->map.so_file,
		cub3D->map.ea_file,
		cub3D->map.we_file);
	ft_printf(BLUE"C: %s\nF: %s\n"RESET,
		cub3D->map.ceiling_color.color_str,
		cub3D->map.floor_color.color_str);
	ft_printf(RED"rows: %d | cols: %d\n"RESET,
		cub3D->map.dimensions.rows,
		cub3D->map.dimensions.columns);
	while (index < cub3D->map.dimensions.rows)
	{
		ft_printf(YELLOW"|"RESET""GREEN"%s"RESET""YELLOW"|\n"RESET,
			cub3D->map.map_matrix[index]);
		index++;
	}
}

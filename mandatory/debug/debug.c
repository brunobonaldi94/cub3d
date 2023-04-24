/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:36:25 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/04/23 23:44:31 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_map(t_cubd *cub3D)
{
	int	index;

	if (!DEBUG)
		return ;
	index = 0;
	while (index < cub3D->map.dimensions.rows)
	{
		ft_printf("%s\n", cub3D->map.map_matrix[index]);
		index++;
	}
	ft_printf("map rows:%d\nmap cols:%d\n",
		cub3D->map.dimensions.rows,
		cub3D->map.dimensions.columns);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 14:46:58 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/04/23 14:48:03 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	close_fd(int fd)
{
	if (fd < 0)
		return ;
	close(fd);
}

void	clear_map_matrix(t_cubd *cub3D)
{
	int	index;

	if (cub3D->map.map_matrix == NULL)
		return ;
	index = 0;
	while (index < cub3D->map.dimensions.rows)
	{
		free(cub3D->map.map_matrix[index]);
		index++;
	}
	free(cub3D->map.map_matrix);
}

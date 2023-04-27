/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:32:59 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/04/26 22:37:19 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	read_map(t_cubd *cub3D, int fd);

int	validate_map(t_cubd *cub3D, char *map_file)
{
	set_file(&cub3D->map.map_file, map_file, CUB_EXTENSION);
	if (cub3D->map.map_file.fd < 0)
		exit_with_message_and_free(cub3D, ERROR_CODE, MAP_IS_NOT_VALID_MESSAGE);
	read_map(cub3D, cub3D->map.map_file.fd);
	close_fd(cub3D->map.map_file.fd);
	return (SUCCESS_CODE);
}

void	read_map(t_cubd *cub3D, int fd)
{
	char	*line;
	t_list	**h_list;

	h_list = &cub3D->map.map_list;
	while (TRUE)
	{
		line = ft_get_next_line(fd);
		if (line == NULL)
			break ;
		ft_lstadd_back(h_list, ft_lstnew(line));
	}
	load_map(cub3D, *h_list);
	print_map(cub3D);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:32:59 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/04/21 22:41:09 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	validate_file_path(char *file_path);

void	set_file(t_file *file, char *file_path)
{
	file->fd = validate_file_path(file_path);
	file->name = file_path;
}

int	validate_map(t_cubd *cub3D, char *map_file)
{
	set_file(&cub3D->map.map_file, map_file);
	close_fd(cub3D->map.map_file.fd);
	return (SUCCESS_CODE);
}

int	validate_file_path(char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("File "GREEN"%s"RESET" does not exist", file_path);
		exit(ERROR_CODE);
	}
	return (fd);
}

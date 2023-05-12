/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_helpers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:18:09 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/10 23:14:02 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	set_file(t_file *file, char *file_path, char *extension)
{
	file->fd = open_file_path(file_path, extension);
	file->name = file_path;
}

int	check_file_extension(char *file_path, char *extension)
{
	char	*file_extension;

	file_extension = ft_strrchr(file_path, '.');
	if (!file_extension)
		return (FALSE);
	return (ft_strcmp(file_extension, extension) == 0);
}

int	open_file_path(char *file_path, char *extension)
{
	int	fd;

	if (!check_file_extension(file_path, extension))
		return (UNINITIALIZED_FD);
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (UNINITIALIZED_FD);
	return (fd);
}

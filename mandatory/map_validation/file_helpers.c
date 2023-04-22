/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:18:09 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/04/22 15:18:26 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_file(t_file *file, char *file_path)
{
	file->fd = open_file_path(file_path);
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

int	open_file_path(char *file_path)
{
	int	fd;

	if (!check_file_extension(file_path, ".cub"))
		exit_with_message(ERROR_CODE, WRONG_CUB_EXTESION_MESSSAGE);
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("File "GREEN"%s"RESET" does not exist", file_path);
		exit(ERROR_CODE);
	}
	return (fd);
}

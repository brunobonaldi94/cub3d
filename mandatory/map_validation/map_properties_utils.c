/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_properties_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:48:42 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/04/26 21:12:43 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*get_texture_path(t_cubd *cub3D, char *texture_path)
{
	char	*path;
	int		fd;

	if (!texture_path || ft_strlen(texture_path) < 4)
		exit_with_message_and_free(cub3D, ERROR_CODE,
			WRONG_TEXTURE_PATH_MESSAGE);
	path = ft_strtrim(texture_path + 3, WHITE_SPACE);
	if (!path)
	{
		ft_free_ptr((void **)&path);
		exit_with_message_and_free(cub3D, ERROR_CODE,
			WRONG_TEXTURE_PATH_MESSAGE);
	}
	fd = open_file_path(path, XPM_EXTENSION);
	if (fd < 0)
	{
		ft_free_ptr((void **)&path);
		exit_with_message_and_free(cub3D, ERROR_CODE,
			WRONG_TEXTURE_PATH_MESSAGE);
	}
	close_fd(fd);
	return (path);
}

void	set_texture_path(t_cubd *cub3D, char **texture, char *texture_path)
{
	if (*texture)
		exit_with_message_and_free(cub3D, ERROR_CODE,
			DUPLICATED_PROPERTY_MESSAGE);
	*texture = get_texture_path(cub3D, texture_path);
}

void	set_floor_ceiling_color(t_cubd *cub3D, t_color *color, char *color_str)
{
	char	**colors_split;
	int		color_count;

	if (!color_str || ft_strlen(color_str) < 3)
		exit_with_message_and_free(cub3D, ERROR_CODE, NO_COLOR_SET_MESSAGE);
	color->color_str = ft_strtrim(color_str + 2, WHITE_SPACE);
	if (!color->color_str)
		exit_with_message_and_free(cub3D, ERROR_CODE, NO_COLOR_SET_MESSAGE);
	if (ft_count_char(color->color_str, ',') > 2)
		exit_with_message_and_free(cub3D, ERROR_CODE, WRONG_COLOR_SET_MESSAGE);
	color_count = 0;
	colors_split = ft_split(color->color_str, ',');
	while (colors_split[color_count])
		color_count++;
	if (color_count != 3)
	{
		ft_free_matrix((void ***)&colors_split);
		exit_with_message_and_free(cub3D, ERROR_CODE, WRONG_COLOR_SET_MESSAGE);
	}
	if (!set_color_rgb(colors_split, color))
	{
		ft_free_matrix((void ***)&colors_split);
		exit_with_message_and_free(cub3D, ERROR_CODE, WRONG_COLOR_SET_MESSAGE);
	}
	ft_free_matrix((void ***)&colors_split);
}

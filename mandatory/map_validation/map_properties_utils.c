/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_properties_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:48:42 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/04/23 17:16:28 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	are_all_map_properties_set(t_cubd *cub3D)
{
	return (cub3D->map.so_file && cub3D->map.no_file && cub3D->map.ea_file
		&& cub3D->map.we_file && cub3D->map.floor_color.color_str
		&& cub3D->map.ceiling_color.color_str);
}

char	*get_texture_path(t_cubd *cub3D, char *texture_path)
{
	char	*path;
	int		fd;

	if (!texture_path || ft_strlen(texture_path) < 4)
		exit_with_message_and_free(cub3D, ERROR_CODE,
			WRONG_TEXTURE_PATH_MESSAGE);
	path = ft_strtrim(texture_path + 3, WHITE_SPACE);
	if (!path)
		exit_with_message_and_free(cub3D, ERROR_CODE,
			WRONG_TEXTURE_PATH_MESSAGE);
	fd = open_file_path(path, XPM_EXTENSION);
	if (fd < 0)
		exit_with_message_and_free(cub3D, ERROR_CODE,
			WRONG_TEXTURE_PATH_MESSAGE);
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

int	is_valid_color_rgb(int color_atoi, char *color_str)
{
	char	*color_trimmed;

	if (color_atoi < 0)
		return (FALSE);
	color_trimmed = ft_strtrim(color_str, WHITE_SPACE);
	if (color_atoi == 0 && ft_strcmp(color_trimmed, "0") != 0)
	{
		ft_free_ptr((void **)&color_trimmed);
		return (FALSE);
	}
	if (!(color_atoi >= 0 && color_atoi <= 255))
	{
		ft_free_ptr((void **)&color_trimmed);
		return (FALSE);
	}
	return (TRUE);
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
	color_count = 0;
	colors_split = ft_split(color->color_str, ',');
	while (colors_split[color_count])
		color_count++;
	if (color_count != 3)
		exit_with_message_and_free(cub3D, ERROR_CODE,
			WRONG_COLOR_SET_MESSAGE);
	color->r = ft_atoi(colors_split[0]);
	color->g = ft_atoi(colors_split[1]);
	color->b = ft_atoi(colors_split[2]);
	if (!is_valid_color_rgb(color->r, colors_split[0])
		|| !is_valid_color_rgb(color->g, colors_split[1])
		|| !is_valid_color_rgb(color->b, colors_split[2]))
	{
		exit_with_message_and_free(cub3D, ERROR_CODE,
			WRONG_COLOR_SET_MESSAGE);
	}
}

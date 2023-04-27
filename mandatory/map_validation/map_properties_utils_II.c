/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_properties_utils_II.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:48:42 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/04/26 22:40:31 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	are_all_map_properties_set(t_cubd *cub3D)
{
	return (cub3D->map.so_file && cub3D->map.no_file && cub3D->map.ea_file
		&& cub3D->map.we_file && cub3D->map.floor_color.color_str
		&& cub3D->map.ceiling_color.color_str);
}

int	is_valid_color_rgb(int color_atoi, char *color_str)
{
	char	*color_trimmed;
	int		is_valid;

	is_valid = TRUE;
	if (color_atoi < 0)
		return (FALSE);
	color_trimmed = ft_strtrim(color_str, WHITE_SPACE);
	if (color_atoi == 0 && ft_strcmp(color_trimmed, "0") != 0)
		is_valid = FALSE;
	else if (!(color_atoi >= 0 && color_atoi <= 255))
		is_valid = FALSE;
	else if (!ft_is_all_something(color_trimmed, ft_isdigit))
		is_valid = FALSE;
	ft_free_ptr((void **)&color_trimmed);
	return (is_valid);
}

int	is_valid_set_of_colors(t_color *color, char **colors_split)
{
	return (is_valid_color_rgb(color->r, colors_split[0])
		&& is_valid_color_rgb(color->g, colors_split[1])
		&& is_valid_color_rgb(color->b, colors_split[2]));
}

int	set_color_rgb(char **colors_split, t_color *color)
{
	color->r = ft_atoi(colors_split[0]);
	color->g = ft_atoi(colors_split[1]);
	color->b = ft_atoi(colors_split[2]);
	return (is_valid_set_of_colors(color, colors_split));
}

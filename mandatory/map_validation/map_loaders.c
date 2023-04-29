/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loaders.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:36:53 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/04/29 20:01:24 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_map_row_colums(t_cubd *cub3D, t_map_dimensions *dim,
			t_list *h_list)
{
	int		map_width;
	int		fst_col_map;
	char	*line;
	int		total_rows;

	dim->columns = 0;
	dim->col_offset = INT_MAX;
	total_rows = ft_lstsize_no_new_line(h_list);
	while (h_list)
	{
		line = (char *)h_list->content;
		if (check_new_line_in_the_middle(h_list))
			exit_with_message_and_free(cub3D, ERROR_CODE, EMPTY_LINE_MESSAGE);
		if (total_rows != dim->rows && !is_valid_map_content(cub3D, line,
				total_rows == dim->rows + 1 || dim->rows == 0))
			exit_with_message_and_free(cub3D, ERROR_CODE,
				NOT_ALLOW_CHARACTER_MESSAGE);
		map_width = ft_strlen_trimmmed_str(line);
		fst_col_map = first_column_map_char(line);
		dim->columns = set_max_or_min(dim->columns, map_width, TRUE);
		dim->col_offset = set_max_or_min(dim->col_offset, fst_col_map, FALSE);
		h_list = h_list->next;
		if (!is_new_line(line))
			dim->rows = dim->rows + 1;
	}
}

int	load_map_content(t_cubd *cub3D, t_list	*h_list)
{
	int	index;

	index = 0;
	set_map_row_colums(cub3D, &cub3D->map.dimensions, h_list);
	cub3D->map.map_matrix = (char **)malloc(sizeof(char *)
			* cub3D->map.dimensions.rows);
	while (index < cub3D->map.dimensions.rows)
	{
		cub3D->map.map_matrix[index] = (char *)malloc(sizeof(char)
				* cub3D->map.dimensions.columns + 1);
		copy_until_new_line(cub3D->map.map_matrix[index],
			((char *)h_list->content) + cub3D->map.dimensions.col_offset,
			cub3D->map.dimensions.columns + 1);
		h_list = h_list->next;
		index++;
	}
	return (TRUE);
}

int	load_map_properties(t_cubd *cub3D, char *line, int *line_nbr)
{
	int	is_map_prop;

	is_map_prop = TRUE;
	advance_ptr_while_white_space(&line);
	if (ft_strncmp(line, SOUTH_PROP, 3) == 0)
		set_texture_path(cub3D, &cub3D->map.so_file, line);
	else if (ft_strncmp(line, NORTH_PROP, 3) == 0)
		set_texture_path(cub3D, &cub3D->map.no_file, line);
	else if (ft_strncmp(line, EAST_PROP, 3) == 0)
		set_texture_path(cub3D, &cub3D->map.ea_file, line);
	else if (ft_strncmp(line, WEST_PROP, 3) == 0)
		set_texture_path(cub3D, &cub3D->map.we_file, line);
	else if (ft_strncmp(line, FLOOR_PROP, 2) == 0)
		set_floor_ceiling_color(cub3D, &cub3D->map.floor_color, line);
	else if (ft_strncmp(line, CEILING_PROP, 2) == 0)
		set_floor_ceiling_color(cub3D, &cub3D->map.ceiling_color, line);
	else if (ft_strcmp(line, "\n") == 0 || !*line)
	{
		if (*line_nbr == 0)
			*line_nbr = -1;
		is_map_prop = TRUE;
	}
	else
		is_map_prop = FALSE;
	return (is_map_prop);
}

int	load_each_map_line(t_cubd *cub3D, t_list	*h_list)
{
	char	*line;
	int		line_nbr;
	int		is_map_prop;

	line_nbr = 0;
	while (h_list)
	{
		line = (char *)h_list->content;
		if (are_all_map_properties_set(cub3D) && ft_strcmp(line, "\n") == 0)
		{
			h_list = h_list->next;
			line_nbr++;
			continue ;
		}
		is_map_prop = load_map_properties(cub3D, line, &line_nbr);
		if (line_nbr == 0 && !is_map_prop)
			exit_with_message_and_free(cub3D, ERROR_CODE,
				MAP_MUST_START_WITH_PROPERTIES_MESSAGE);
		if (!is_map_prop && are_all_map_properties_set(cub3D))
			return (load_map_content(cub3D, h_list));
		h_list = h_list->next;
		line_nbr++;
	}
	return (TRUE);
}

void	load_map(t_cubd *cub3D, t_list	*h_list)
{
	load_each_map_line(cub3D, h_list);
	if (are_all_map_properties_set(cub3D) == FALSE)
		exit_with_message_and_free(cub3D, ERROR_CODE,
			MAP_PROPERTY_MISSING_MESSAGE);
	if (cub3D->map.dimensions.rows <= 2 || cub3D->map.dimensions.columns <= 2)
		exit_with_message_and_free(cub3D, ERROR_CODE,
			WRONG_MAP_DIMENSIONS_MESSAGE);
	if (cub3D->map.found_player != 1)
		exit_with_message_and_free(cub3D, ERROR_CODE,
			PLAYER_ERROR_MESSAGE);
	if (!is_player_inside_map(cub3D->map.map_matrix, &cub3D->map.dimensions))
		exit_with_message_and_free(cub3D, ERROR_CODE,
			PLAYER_MUST_BE_INSIDE_MAP_MESSAGE);
}

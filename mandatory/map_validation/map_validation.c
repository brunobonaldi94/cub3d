/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:32:59 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/04/25 22:49:52 by bbonaldi         ###   ########.fr       */
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

int	check_new_line_in_the_middle(t_list *h_list)
{
	char	*line;

	line = (char *)h_list->content;
	if (!is_new_line(line))
		return (FALSE);
	while (h_list)
	{
		line = (char *)h_list->content;
		while (*line)
		{
			if (!ft_strchr(WHITE_SPACE, *line))
				return (TRUE);
			line++;
		}
		h_list = h_list->next;
	}
	return (FALSE);
}

void	set_map_row_colums(t_cubd *cub3D, t_map_dimensions *map_dim,
			t_list *h_list)
{
	int		map_width;
	int		first_col_map_char;
	char	*line;
	int		total_rows;

	map_dim->columns = 0;
	map_dim->col_offset = INT_MAX;
	total_rows = ft_lstsize_no_new_line(h_list);
	while (h_list)
	{
		line = (char *)h_list->content;
		if (check_new_line_in_the_middle(h_list))
			exit_with_message_and_free(cub3D, ERROR_CODE, EMPTY_LINE_MESSAGE);
		if (total_rows != map_dim->rows
			&& !is_valid_map_content(cub3D, line,
				total_rows == map_dim->rows + 1 || map_dim->rows == 0))
			exit_with_message_and_free(cub3D, ERROR_CODE,
				NOT_ALLOW_CHARACTER_MESSAGE);
		map_width = ft_strlen_trimmmed_str(line);
		first_col_map_char = first_column_map_char(line);
		if (map_dim->columns < map_width)
			map_dim->columns = map_width;
		if (map_dim->col_offset > first_col_map_char)
			map_dim->col_offset = first_col_map_char;
		h_list = h_list->next;
		if (!is_new_line(line))
			map_dim->rows = map_dim->rows + 1;
	}
}

size_t	copy_until_new_line(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = ft_strlen(src);
	if (size == 0)
		return (len);
	while (*src && --size && *src != '\n')
		*dst++ = *src++;
	while (size)
	{
		*dst++ = ' ';
		size--;
	}
	*dst = '\0';
	return (len);
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
			((char *)h_list->content) + cub3D->map.dimensions.col_offset, cub3D->map.dimensions.columns + 1);
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

int load_each_map_line(t_cubd *cub3D, t_list	*h_list)
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

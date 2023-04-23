/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:32:59 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/04/22 23:39:38 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	read_map(t_cubd *cub3D, int fd);

int	validate_map(t_cubd *cub3D, char *map_file)
{
	set_file(&cub3D->map.map_file, map_file);
	read_map(cub3D, cub3D->map.map_file.fd);
	close_fd(cub3D->map.map_file.fd);
	return (SUCCESS_CODE);
}

int are_all_map_properties_set(t_cubd *cub3D)
{
	return (cub3D->map.so_file && cub3D->map.no_file && cub3D->map.ea_file
		&& cub3D->map.we_file && cub3D->map.floor_color
		&& cub3D->map.ceiling_color);
}

int	first_last_row_wall_checker(char *line)
{
	advance_ptr_while_white_space(&line);
	while (*line)
	{
		if (*line != WALL_CHAR)
			break ;
		line++;
	}
	advance_ptr_while_white_space(&line);
	if (*line)
		return (FALSE);
	return (TRUE);
}

int	is_valid_map_content(char *line, int is_first_or_last_row)
{
	if (is_first_or_last_row)
		return (first_last_row_wall_checker(line));
	advance_ptr_while_white_space(&line);
	if (*line != WALL_CHAR)
		return (FALSE);
	while (*line)
	{
		if (ft_strchr(ALLOWED_MAP_CHARS, *line) == NULL && *line != '\n')
			return (FALSE);
		line++;
	}
	line = line - 2;
	if (*line != WALL_CHAR)
		return (FALSE);
	return (TRUE);
}

void	set_map_row_colums(t_map_dimensions	*map_dim, t_list *h_list)
{
	int		map_width;
	char	*line;
	int		total_rows;

	map_dim->columns = 0;
	total_rows = ft_lstsize(h_list);
	while (h_list)
	{
		line = (char *)h_list->content;
		if (line && ft_strcmp(line, "\n") == 0)
			exit_with_message(ERROR_CODE, MAP_EMPTY_LINE_MESSAGE); // must free all program
		if (!is_valid_map_content(line, total_rows == map_dim->rows + 1
				|| map_dim->rows == 0))
			exit_with_message(ERROR_CODE, NOT_ALLOW_CHARACTER_MESSAGE); // must free all program
		map_width = ft_strlen(line);
		if (map_dim->columns < map_width)
			map_dim->columns = map_width;
		h_list = h_list->next;
		map_dim->rows = map_dim->rows + 1;
	}
	map_dim->columns = map_dim->columns - 1;
}

int load_map_content(t_cubd *cub3D, t_list	*h_list)
{
	int	index;

	index = 0;
	set_map_row_colums(&cub3D->map.dimensions, h_list);
	cub3D->map.map_matrix = (char **)malloc(sizeof(char *)
			* cub3D->map.dimensions.rows);
	while (h_list)
	{
		cub3D->map.map_matrix[index] = (char *)malloc(sizeof(char)
				* cub3D->map.dimensions.columns + 1);
		ft_strlcpy(cub3D->map.map_matrix[index], (char *)h_list->content,
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
		cub3D->map.so_file = ft_strtrim(line + 3, WHITE_SPACE);
	else if (ft_strncmp(line, NORTH_PROP, 3) == 0)
		cub3D->map.no_file = ft_strtrim(line + 3, WHITE_SPACE);
	else if (ft_strncmp(line, EAST_PROP, 3) == 0)
		cub3D->map.ea_file = ft_strtrim(line + 3, WHITE_SPACE);
	else if (ft_strncmp(line, WEST_PROP, 3) == 0)
		cub3D->map.we_file = ft_strtrim(line + 3, WHITE_SPACE);
	else if (ft_strncmp(line, FLOOR_PROP, 2) == 0)
		cub3D->map.floor_color = ft_strtrim(line + 2, WHITE_SPACE);
	else if (ft_strncmp(line, CEILING_PROP, 2) == 0)
		cub3D->map.ceiling_color = ft_strtrim(line + 2, WHITE_SPACE);
	else if (ft_strcmp(line, "\n") == 0)
	{
		if (*line_nbr == 0)
			*line_nbr = -1;
		is_map_prop = TRUE;
	}
	else
		is_map_prop = FALSE;
	return (is_map_prop);
}

int	load_map(t_cubd *cub3D, t_list	*h_list)
{
	int	is_map_prop;
	int line_nbr;
	char *line;

	line_nbr = 0;
	while (h_list)
	{
		line = (char *)h_list->content;
		if (are_all_map_properties_set(cub3D) && ft_strcmp(line, "\n") == 0)
		{
			h_list = h_list->next;
			line_nbr++;
			continue;
		}
		is_map_prop = load_map_properties(cub3D, line, &line_nbr);
		if (line_nbr == 0 && !is_map_prop)
			exit_with_message(ERROR_CODE, "Map file is not valid"); // must free all program
		if (!is_map_prop && are_all_map_properties_set(cub3D))
		{
			load_map_content(cub3D, h_list);
			break ;
		}
		h_list = h_list->next;
		line_nbr++;
	}
	if (are_all_map_properties_set(cub3D) == FALSE)
		exit_with_message(ERROR_CODE, MAP_PROPERTY_MISSING_MESSAGE); // must free all program
	if (cub3D->map.dimensions.rows == 0 || cub3D->map.dimensions.columns == 0)
		exit_with_message(ERROR_CODE, WRONG_MAP_DIMENSIONS_MESSAGE); // must free all program
	return (is_map_prop);
}

void	read_map(t_cubd *cub3D, int fd)
{
	char	*line;
	t_list	*h_list;

	h_list = NULL;
	while (TRUE)
	{
		line = ft_get_next_line(fd);
		if (line == NULL)
			break ;
		ft_lstadd_back(&h_list, ft_lstnew(line));
	}
	load_map(cub3D, h_list);
	int i = 0;
	while (i < cub3D->map.dimensions.rows)
	{
		ft_printf("%s\n", cub3D->map.map_matrix[i]);
		i++;
	}
	ft_lstclear(&h_list, free);
}

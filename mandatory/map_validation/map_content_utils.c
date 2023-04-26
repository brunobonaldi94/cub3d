/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:49:59 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/04/25 19:25:04 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3D.h"

int	first_last_row_wall_checker(char *line);
int	is_valid_map_content(t_cubd *cub3D, char *line, int is_first_or_last_row);

int	is_valid_map_content(t_cubd *cub3D, char *line, int is_first_or_last_row)
{
	char	*start_line;

	start_line = line;
	if (is_first_or_last_row)
		return (first_last_row_wall_checker(line));
	advance_ptr_while_white_space(&line);
	if (*line != WALL_CHAR)
		return (FALSE);
	while (*line)
	{
		if (ft_strchr(PLAYER_CHAR, *line))
			cub3D->map.found_player += 1;
		if (ft_strchr(ALLOWED_MAP_CHARS, *line) == NULL && *line != '\n')
			return (FALSE);
		line++;
	}
	go_back_ptr_while_white_space(start_line, &line);
	if (*line != WALL_CHAR)
		return (FALSE);
	return (TRUE);
}

int	first_last_row_wall_checker(char *line)
{
	advance_ptr_while_white_space(&line);
	while (*line)
	{
		if (*line != WALL_CHAR && *line != ' ')
			break ;
		line++;
	}
	advance_ptr_while_white_space(&line);
	if (*line)
		return (FALSE);
	return (TRUE);
}

int	is_wall_or_empty(char map_char)
{
	return (map_char == WALL_CHAR || map_char == EMPTY_CHAR);
}

t_cord	find_player_in_map(char **map, t_map_dimensions *dim)
{
	t_cord	cord;

	cord.y = 0;
	while (cord.y < dim->rows)
	{
		cord.x = 0;
		while (cord.x < dim->columns && map[cord.y][cord.x])
		{
			if (ft_strchr(PLAYER_CHAR, map[cord.y][cord.x]))
				return (cord);
			cord.x++;
		}
		cord.y++;
	}
	return ((t_cord){-1, -1});
}

int	is_player_inside_map(char **map, t_map_dimensions *dim)
{
	int		x;
	int		y;
	t_cord	cord;

	cord = find_player_in_map(map, dim);
	if (cord.x == -1 && cord.y == -1)
		return (FALSE);
	y = cord.y;
	x = cord.x;
	if (!is_wall_or_empty(map[y - 1][x])
		|| !is_wall_or_empty(map[y][x - 1])
		|| !is_wall_or_empty(map[y][x + 1])
		|| !is_wall_or_empty(map[y + 1][x]))
		return (FALSE);
	return (TRUE);
}

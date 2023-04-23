/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:49:59 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/04/23 15:50:27 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3D.h"

int	first_last_row_wall_checker(char *line);
int	is_valid_map_content(char *line, int is_first_or_last_row);

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:17:17 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/04/23 22:59:48 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		first_last_row_wall_checker(char *line);
void	advance_ptr_while_white_space(char **line);
int		is_valid_map_content(char *line, int is_first_or_last_row);

void	advance_ptr_while_white_space(char **line)
{
	while (**line && ft_strchr(WHITE_SPACE, **line))
		(*line)++;
}

int	is_new_line(char *line)
{
	return (line && ft_strcmp(line, "\n") == 0);
}

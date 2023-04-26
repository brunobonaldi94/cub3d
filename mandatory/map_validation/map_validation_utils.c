/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:17:17 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/04/25 22:51:16 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		first_last_row_wall_checker(char *line);
void	advance_ptr_while_white_space(char **line);

void	advance_ptr_while_white_space(char **line)
{
	while (**line && ft_strchr(WHITE_SPACE, **line))
		(*line)++;
}

void	go_back_ptr_while_white_space(char *start_ptr, char **line)
{
	while (ft_strchr(WHITE_SPACE, **line))
	{
		if (*line == start_ptr)
			break ;
		(*line)--;
	}
}

int	is_new_line(char *line)
{
	return (line && ft_strcmp(line, "\n") == 0);
}

int	ft_lstsize_no_new_line(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		if (!is_new_line((char *)lst->content))
			size++;
		lst = lst->next;
	}
	return (size);
}

size_t	ft_strlen_trimmmed_str(char *str)
{
	char	*trimmed_str;
	size_t	len;

	if (!str)
		return (0);
	trimmed_str = ft_strtrim(str, WHITE_SPACE);
	len = ft_strlen(trimmed_str);
	ft_free_ptr((void **)&trimmed_str);
	return (len);
}

size_t	first_column_map_char(char *str)
{
	size_t	first_col;

	first_col = 0;
	while (*str)
	{
		if (ft_strchr(ALLOWED_MAP_CHARS_NO_WHT_SPC, *str))
			break ;
		str++;
		first_col++;
	}
	return (first_col);
}

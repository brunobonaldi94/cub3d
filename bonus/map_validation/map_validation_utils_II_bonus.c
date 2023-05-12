/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils_II_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:17:17 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/10 23:14:25 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

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

int	set_max_or_min(int current, int next, int is_max)
{
	if (is_max)
	{
		if (current < next)
			current = next;
		return (current);
	}
	if (current > next)
		current = next;
	return (current);
}

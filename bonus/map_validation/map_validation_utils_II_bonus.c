/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils_II_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:17:17 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/12 09:32:02 by bbonaldi         ###   ########.fr       */
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
	size_t	src_len;
	size_t	qty_copied;
	size_t	original_size;

	src_len = ft_strlen(src);
	original_size = size;
	if (size == 0)
		return (src_len);
	qty_copied = 0;
	while (src[qty_copied] && (qty_copied < size - 1)
		&& src[qty_copied] != '\n')
	{
		dst[qty_copied] = src[qty_copied];
		qty_copied++;
	}
	while (qty_copied < size - 1)
	{
		dst[qty_copied] = ' ';
		qty_copied++;
	}
	dst[original_size - 1] = '\0';
	return (src_len);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:17:17 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/10 23:14:26 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

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

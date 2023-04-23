/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:17:17 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/04/22 23:20:09 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	advance_ptr_while_white_space(char **line)
{
	while (**line && ft_strchr(WHITE_SPACE, **line))
		(*line)++;
}

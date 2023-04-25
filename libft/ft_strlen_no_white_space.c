/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_no_white_space.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:02:25 by harndt            #+#    #+#             */
/*   Updated: 2023/04/24 22:27:58 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_no_white_space(const char *str)
{
	size_t	size;
	size_t	white_space;

	size = 0;
	white_space = 0;
	while (str[size])
	{
		if (ft_strchr(WHITE_SPACE_CHARS, str[size]))
			white_space++;
		size++;
	}
	return (size - white_space);
}

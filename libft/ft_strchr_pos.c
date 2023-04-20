/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:40:31 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/10/31 23:50:34 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr_pos(const char *s, int c)
{
	size_t	index;

	index = 0;
	while (*s != (char)c)
	{
		if (!*s)
			return (-1);
		s++;
		index++;
	}
	return (index);
}

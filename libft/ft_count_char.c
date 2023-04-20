/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:42:35 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/11/16 22:13:21 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_char(char *str, char c)
{
	int	count;

	count = 0;
	if (!str)
		return (count);
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

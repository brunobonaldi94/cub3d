/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:10:51 by harndt            #+#    #+#             */
/*   Updated: 2022/07/19 20:24:44 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
		if (*str++ == (char)c)
			return ((char *)(str - 1));
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <humberto.arndt@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:22:14 by harndt            #+#    #+#             */
/*   Updated: 2022/04/29 20:15:15 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	malloc_size;

	if (!s)
		return (NULL);
	if (start < ft_strlen(s))
		malloc_size = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (malloc_size > len)
		malloc_size = len;
	str = (char *)malloc(malloc_size + 1);
	if (!str)
		return (NULL);
	if (malloc_size == 0)
	{
		str[0] = '\0';
		return (str);
	}
	ft_strlcpy(str, (s + start), (malloc_size + 1));
	return (str);
}

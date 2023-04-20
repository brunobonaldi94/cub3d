/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <humberto.arndt@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:39:03 by harndt            #+#    #+#             */
/*   Updated: 2022/04/25 15:57:53 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{	
	size_t	i;
	size_t	j;

	if (!*s2)
		return ((char *)s1);
	i = 0;
	while (s1[i] != '\0' && i < n)
	{
		j = 0;
		while (s1[i + j] == s2[j] && s2[j] != '\0' && (i + j < n))
			j++;
		if (s2[j] == '\0')
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpyline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 21:47:57 by harndt            #+#    #+#             */
/*   Updated: 2022/07/11 21:48:16 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_cpyline(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (src[i] != '\n' && src[i])
		dst[len++] = src[i++];
	if (src[i] == '\n')
		dst[len++] = '\n';
	dst[len] = '\0';
	return (len);
}

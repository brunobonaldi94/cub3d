/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <humberto.arndt@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:32:39 by harndt            #+#    #+#             */
/*   Updated: 2022/04/25 15:56:14 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	if (!n)
		return (0);
	while (*(unsigned char *)str1++ == *(unsigned char *)str2++ && --n)
		;
	return (*(unsigned char *)(--str1) - *(unsigned char *)(--str2));
}

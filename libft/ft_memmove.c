/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <humberto.arndt@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:16:34 by harndt            #+#    #+#             */
/*   Updated: 2022/04/25 15:56:24 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_uc;
	unsigned char	*src_uc;

	dst_uc = (unsigned char *)dst;
	src_uc = (unsigned char *)src;
	if (src_uc < dst_uc)
	{
		while (n--)
			dst_uc[n] = src_uc[n];
	}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}

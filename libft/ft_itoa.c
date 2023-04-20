/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <humberto.arndt@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 01:54:00 by harndt            #+#    #+#             */
/*   Updated: 2022/04/29 20:14:33 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Recursive function to count the lenght of an Integer.
 * @param n Integer traversed to find length.
 * @param len Total of digits in n.
 * @return Lenght of Integer n.
 **/
static size_t	ft_declen(size_t n, size_t len)
{
	if (n > 9)
		return (ft_declen(n / 10, len + 1));
	return (len);
}

/**
 * @brief Funtion to convert Integer to String.
 * @param str Array that will store the conversion.
 * @param n Integer to be converted.
**/
static void	ft_decstr(char *str, long n)
{
	if (n > 9)
		ft_decstr(str - 1, n / 10);
	*str = n % 10 + '0';
}

char	*ft_itoa(int n)
{
	char	*str;
	long	n_l;
	size_t	len;

	n_l = (long)n;
	if (n < 0)
		n_l = -n_l;
	len = ft_declen(n_l, 1);
	if (n < 0)
		len++;
	str = (char *) malloc (len * sizeof(char) + 1);
	if (!str)
		return (NULL);
	if (n < 0)
		*str = '-';
	ft_decstr(str + len -1, n_l);
	*(str + len) = '\0';
	return (str);
}

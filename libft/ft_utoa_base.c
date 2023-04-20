/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:43:54 by harndt            #+#    #+#             */
/*   Updated: 2022/05/27 18:14:12 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Converts Unsigned Int 'n' into char.
 * @param n Unsigned int to convert.
 * @return Unsigned int converted.
 */
static char	ft_get_utoa(unsigned long n)
{
	char	c;

	c = (char)n + '0';
	if (c > '9')
		c += 39;
	return (c);
}

/**
 * @brief Find the length of the ungsigned int received.
 * @param n Unsigned Int to convert into ASCII.
 * @param base Base to be converted into.
 * @return How many digits are in Unsigned int 'n'.
 */
static size_t	ft_utoa_len(unsigned long n, int base)
{
	size_t	length;

	length = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / base;
		length++;
	}
	return (length);
}

char	*ft_utoa_base(unsigned long n, int base)
{
	char	*string;
	size_t	length;

	length = ft_utoa_len(n, base) + 1;
	string = (char *)malloc(length * sizeof(char));
	if (!string)
		return (NULL);
	string[--length] = '\0';
	while (length > 0)
	{
		string[--length] = ft_get_utoa(n % base);
		n = n / base;
	}
	return (string);
}

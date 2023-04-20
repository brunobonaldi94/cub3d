/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_upperx.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:41:31 by harndt            #+#    #+#             */
/*   Updated: 2022/07/19 22:39:23 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_specifier_upperx(va_list arg_ptr)
{
	char	*string;
	int		length;
	int		i;

	i = -1;
	string = ft_utoa_base(va_arg(arg_ptr, unsigned int), HEX);
	length = ft_strlen(string);
	while (string[++i])
	{
		if (string[i] >= 'a' && string[i] <= 'z')
			string[i] -= 32;
	}
	ft_putstr(string);
	if (string)
		free(string);
	return (length);
}

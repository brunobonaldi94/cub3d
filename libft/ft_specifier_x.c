/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:41:04 by harndt            #+#    #+#             */
/*   Updated: 2022/07/19 22:39:27 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_specifier_x(va_list arg_ptr)
{
	char	*string;
	int		length;

	string = ft_utoa_base(va_arg(arg_ptr, unsigned int), HEX);
	length = ft_strlen(string);
	ft_putstr(string);
	if (string)
		free(string);
	return (length);
}

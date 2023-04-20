/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:40:09 by harndt            #+#    #+#             */
/*   Updated: 2022/07/19 22:39:05 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_specifier_d(va_list arg_ptr)
{
	char	*string;
	int		length;

	string = ft_itoa(va_arg(arg_ptr, int));
	length = ft_strlen(string);
	ft_putstr(string);
	if (string)
		free(string);
	return (length);
}

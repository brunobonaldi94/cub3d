/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:33:09 by harndt            #+#    #+#             */
/*   Updated: 2022/07/11 22:06:28 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Assign the mandatory specifiers functions into an array.
 * @param specifiers An array with length 9.
**/
static void	assign_specifiers(t_specifier *specifiers)
{
	*specifiers++ = ft_specifier_c;
	*specifiers++ = ft_specifier_s;
	*specifiers++ = ft_specifier_p;
	*specifiers++ = ft_specifier_d;
	*specifiers++ = ft_specifier_d;
	*specifiers++ = ft_specifier_u;
	*specifiers++ = ft_specifier_x;
	*specifiers++ = ft_specifier_upperx;
	*specifiers++ = ft_specifier_percent;
}

int	ft_printf(const char *format, ...)
{
	int			length;
	va_list		arg_ptr;
	t_specifier	specifiers[9];

	assign_specifiers(specifiers);
	length = 0;
	va_start(arg_ptr, format);
	while (*format)
	{
		if (*format == DELIMITER && ft_strnchr(FORMATS, *(format +1)) != -1)
			length += specifiers[ft_strnchr(FORMATS, *(++format))](arg_ptr);
		else
		{
			ft_putchar(*format);
			length++;
		}
		format++;
	}
	va_end(arg_ptr);
	return (length);
}

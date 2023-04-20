/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_percent.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:42:07 by harndt            #+#    #+#             */
/*   Updated: 2022/07/19 22:39:12 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_specifier_percent(va_list arg_ptr)
{
	(void)arg_ptr;
	ft_putchar('%');
	return (1);
}

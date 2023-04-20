/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:30:51 by harndt            #+#    #+#             */
/*   Updated: 2022/09/09 20:23:42 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_isnum(char *str)
{
	if (!*str)
		return (FALSE);
	if (*str == '-')
		str++;
	while (*str)
		if (!ft_isdigit(*str++))
			return (FALSE);
	return (TRUE);
}

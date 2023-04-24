/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_all_something.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:30:51 by harndt            #+#    #+#             */
/*   Updated: 2023/04/23 23:40:02 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_all_something(char *str, int (*f)(int))
{
	while (*str)
	{
		if (!f(*str))
			return (FALSE);
		str++;
	}
	return (TRUE);
}

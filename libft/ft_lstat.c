/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 23:32:09 by harndt            #+#    #+#             */
/*   Updated: 2022/10/10 23:32:17 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstat(t_list *list, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i++ < n)
	{
		if (!list)
			break ;
		list = list->next;
	}
	return (list);
}

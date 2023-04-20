/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:05:06 by harndt            #+#    #+#             */
/*   Updated: 2022/10/12 16:05:30 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *list, void *data, int (*cmp)())
{
	while (list)
	{
		if (cmp(list->content, data))
			break ;
		list = list->next;
	}
	return (list);
}

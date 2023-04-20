/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 01:05:23 by harndt            #+#    #+#             */
/*   Updated: 2022/11/09 21:14:16 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*t_node;

	while (*lst)
	{
		t_node = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(t_node, del);
	}
}

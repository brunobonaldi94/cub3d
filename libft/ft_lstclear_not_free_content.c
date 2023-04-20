/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_not_free_content.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 01:05:23 by harndt            #+#    #+#             */
/*   Updated: 2022/11/10 19:53:22 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstdelone_not_free_content(t_list *lst, void (*del)(void *))
{
	if (lst && del)
		del(lst);
}

void	ft_lstclear_not_free_content(t_list **lst, void (*del)(void *))
{
	t_list	*t_node;

	while (*lst)
	{
		t_node = *lst;
		*lst = (*lst)->next;
		ft_lstdelone_not_free_content(t_node, del);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <humberto.arndt@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 01:10:38 by harndt            #+#    #+#             */
/*   Updated: 2022/04/25 15:55:37 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *))
{
	t_list	*new;
	t_list	*first;

	if (!lst)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (NULL);
	first = new;
	while (lst->next)
	{
		lst = lst->next;
		new->next = ft_lstnew(f(lst->content));
		if (!new->next)
		{
			ft_lstclear(&first, del);
			break ;
		}
		new = new->next;
	}
	return (first);
}

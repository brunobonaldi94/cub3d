/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 23:30:56 by harndt            #+#    #+#             */
/*   Updated: 2022/10/12 16:25:38 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Swaps position at the given lists.
 * @param t_list The first list to be swapped.
 * @param t_list The second list to be swapped.
**/
static void	swap(t_list *a, t_list *b)
{
	void	*tmp;

	tmp = a->content;
	a->content = b->content;
	b->content = tmp;
}

/**
 * @brief Breaks the list and input index to sort it.
 * @param t_list The list to be sorted.
 * @param int The first position.
 * @param int The last postion.
 * @return The positon index.
**/
static int	partition(t_list *list, int start, int end)
{
	int		i;
	t_list	*pivot;
	t_list	*current;
	int		pivot_index;

	i = start;
	pivot_index = start;
	pivot = ft_lstat(list, end);
	while (i < end)
	{
		current = ft_lstat(list, i);
		if (*(int *)current->content < *(int *)pivot->content)
		{
			swap(current, ft_lstat(list, pivot_index));
			pivot_index++;
		}
		i++;
	}
	swap(ft_lstat(list, pivot_index), pivot);
	return (pivot_index);
}

void	ft_lstsort(t_list *list, int start, int end)
{
	int	index;

	if (start >= end)
		return ;
	index = partition(list, start, end);
	ft_lstsort(list, start, index - 1);
	ft_lstsort(list, index + 1, end);
}

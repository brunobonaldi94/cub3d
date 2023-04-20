/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:08:15 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/11/17 21:40:32 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_matrix(void ***matrix)
{
	size_t	row_index;
	size_t	col_index;

	row_index = 0;
	col_index = 0;
	if (!matrix || !matrix[row_index])
		return ;
	while (matrix[row_index][col_index])
	{
		ft_free_ptr((void **)&(matrix[row_index][col_index]));
		col_index++;
	}
	free(matrix[row_index]);
	matrix[row_index] = NULL;
}

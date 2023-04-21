/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 22:19:44 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/04/21 16:01:05 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_error(char *message)
{
	ft_printf("%s\n%s\n", "Error", message);
}

int	exit_with_message(int status_code, char *message)
{
	print_error(message);
	exit(status_code);
}

int	has_valid_args(int argc)
{
	if (argc != 2)
		return (FALSE);
	return (TRUE);
}

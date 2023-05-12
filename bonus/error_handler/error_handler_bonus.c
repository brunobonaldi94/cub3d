/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 22:19:44 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/10 23:13:34 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

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

void	exit_with_message_and_free(t_cubd *cub3d, int status_code,
			char *message)
{
	game_clear(cub3d);
	exit_with_message(status_code, message);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:31:49 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/04/21 16:44:44 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "defines.h"
# include "structs.h"
# include <mlx.h>
# include "stdlib.h"
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include "../../libft/libft.h"

// =============================================================================
// GAME_INIT
// =============================================================================
int		init_mlx(t_cub3D *cub3D);
int		init_game(t_cub3D *cub3D, char *argv[]);
void	init_variables(t_cub3D *cub3D);
// =============================================================================
// ERROR HANDLER
// =============================================================================
void	print_error(char *message);
int		exit_with_message(int status_code, char *message);
int		has_valid_args(int argc);
// =============================================================================
// GAME EVENTS
// =============================================================================
void	game_loop_events(t_cub3D *cub3D);
// =============================================================================
// MAP VALIDATION
// =============================================================================
int		validate_file_path(char *file_path);
int		validate_map(t_cub3D *cub3D, char *map_file);
// =============================================================================
// GAME EXIT
// =============================================================================
void	destroy_window(t_cub3D *cub3D);
void	destroy_display(t_cub3D *cub3D);
int		game_exit(t_cub3D *cub3D);
void	close_fd(int fd);
#endif

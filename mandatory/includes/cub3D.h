/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:31:49 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/04/25 18:32:00 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../../libft/libft.h"
# include "defines.h"
# include "structs.h"
# include <mlx.h>
# include "stdlib.h"
# include <math.h>
# include <unistd.h>
# include <fcntl.h>

// =============================================================================
// GAME_INIT
// =============================================================================
int		init_mlx(t_cubd *cub3D);
int		init_game(t_cubd *cub3D, char *argv[]);
void	init_variables(t_cubd *cub3D);
// =============================================================================
// ERROR HANDLER
// =============================================================================
void	print_error(char *message);
int		exit_with_message(int status_code, char *message);
int		has_valid_args(int argc);
void	exit_with_message_and_free(t_cubd *cub3d, int status_code,
			char *message);
// =============================================================================
// GAME EVENTS
// =============================================================================
void	game_loop_events(t_cubd *cub3D);
// =============================================================================
// MAP VALIDATION
// =============================================================================
int		open_file_path(char *file_path, char *extension);
void	set_file(t_file *file, char *file_path, char *extension);
int		check_file_extension(char *file_path, char *extension);
char	*get_texture_path(t_cubd *cub3D, char *texture_path);
void	set_texture_path(t_cubd *cub3D, char **texture, char *texture_path);
void	set_floor_ceiling_color(t_cubd *cub3D, t_color *color,
			char *color_str);
int		validate_map(t_cubd *cub3D, char *map_file);
int		are_all_map_properties_set(t_cubd *cub3D);
int		first_last_row_wall_checker(char *line);
void	advance_ptr_while_white_space(char **line);
void	go_back_ptr_while_white_space(char *start_ptr, char **line);
int		is_valid_map_content(t_cubd *cub3D, char *line,
			int is_first_or_last_row);
int		is_new_line(char *line);
int		is_map_content(char *line);
int		ft_lstsize_no_new_line(t_list *lst);
int		is_player_inside_map(char **map, t_map_dimensions *dim);
size_t	ft_strlen_trimmmed_str(char *str);
// =============================================================================
// GAME EXIT
// =============================================================================
void	destroy_window(t_cubd *cub3D);
void	destroy_display(t_cubd *cub3D);
int		game_exit(t_cubd *cub3D);
void	close_fd(int fd);
void	game_clear(t_cubd *cub3D);
void	clear_map_matrix(t_cubd *cub3D);
// =============================================================================
// DEBUG
// =============================================================================
void	print_map(t_cubd *cub3D);
#endif

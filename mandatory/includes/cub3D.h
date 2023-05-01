/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:31:49 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/04/23 23:00:05 by bbonaldi         ###   ########.fr       */
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
int		is_valid_map_content(char *line, int is_first_or_last_row);
int		is_new_line(char *line);
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





// IMPLEMENTATION SJHONY-X TESTS


int			game_render(t_cubd *cub3D);
char		**generate_map(char *path);
t_window	get_window_size(char **map);
int			render_rect(t_cubd *cub3d, t_rectangle *rect, int x, int y);
void    	render_player(t_cubd *cub3d, t_player *player);
void    	init_player(t_cubd *cub3d, t_player *player);
t_rectangle	*create_rect(int x, int y, int width, int height);
void		set_color_rect(t_rectangle *rect, int color);
int 		draw_rect(t_img *img, t_rectangle *rect);
int 		draw_line(t_cubd *cub3d, t_line *line);
void    	move_player_events(t_cubd *cub3d, t_player *player, int key);

void    move_player(t_cubd *cub3d);


int	key_up(int key, t_cubd *cub3d);
int	key_down(int key, t_cubd *cub3d);


void    cast_all_rays(t_cubd *cub3d, t_player *player, int color);
#endif

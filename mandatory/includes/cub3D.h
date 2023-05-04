/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:31:49 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/03 22:54:12 by bbonaldi         ###   ########.fr       */
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
int			init_mlx(t_cubd *cub3D);
int			init_game(t_cubd *cub3D, char *argv[]);
void		init_variables(t_cubd *cub3D);
void		init_map(t_map	*map);
void		init_colors(t_color *color);
// =============================================================================
// ERROR HANDLER
// =============================================================================
void		print_error(char *message);
int			exit_with_message(int status_code, char *message);
int			has_valid_args(int argc);
void		exit_with_message_and_free(t_cubd *cub3d, int status_code,
				char *message);
// =============================================================================
// GAME EVENTS
// =============================================================================
void		game_loop_events(t_cubd *cub3D);
// =============================================================================
// MAP VALIDATION
// =============================================================================
int			open_file_path(char *file_path, char *extension);
void		set_file(t_file *file, char *file_path, char *extension);
int			check_file_extension(char *file_path, char *extension);
char		*get_texture_path(t_cubd *cub3D, char *texture_path);
void		set_texture_path(t_cubd *cub3D, char **texture, char *texture_path);
void		set_floor_ceiling_color(t_cubd *cub3D, t_color *color,
				char *color_str);
int			validate_map(t_cubd *cub3D, char *map_file);
int			are_all_map_properties_set(t_cubd *cub3D);
int			first_last_row_wall_checker(char *line);
void		advance_ptr_while_white_space(char **line);
void		go_back_ptr_while_white_space(char *start_ptr, char **line);
int			is_valid_map_content(t_cubd *cub3D, char *line,
				int is_first_or_last_row);
int			is_new_line(char *line);
int			is_map_content(char *line);
int			ft_lstsize_no_new_line(t_list *lst);
t_cord		find_player_inside_map(char **map, t_map_dimensions *dim);
size_t		ft_strlen_trimmmed_str(char *str);
size_t		first_column_map_char(char *str);
size_t		copy_until_new_line(char *dst, const char *src, size_t size);
int			set_color_rgb(char **colors_split, t_color *color);
int			check_new_line_in_the_middle(t_list *h_list);
int			set_max_or_min(int current, int next, int is_max);
void		set_floor_ceiling_color(t_cubd *cub3D, t_color *color,
				char *color_str);
void		load_map(t_cubd *cub3D, t_list	*h_list);
int			are_all_map_properties_set(t_cubd *cub3D);
int			is_valid_color_rgb(int color_atoi, char *color_str);
int			is_valid_set_of_colors(t_color *color, char **colors_split);
int			set_color_rgb(char **colors_split, t_color *color);
int			is_player_inside_map(t_cord cord);
void		set_player_position(t_player *player, t_cord cord);
// =============================================================================
// GAME EXIT
// =============================================================================
void		destroy_window(t_cubd *cub3D);
void		destroy_display(t_cubd *cub3D);
int			game_exit(t_cubd *cub3D);
void		close_fd(int fd);
void		game_clear(t_cubd *cub3D);
void		clear_map_matrix(t_cubd *cub3D);
// =============================================================================
// DEBUG
// =============================================================================
void		print_map(t_cubd *cub3D);
// IMPLEMENTATION SJHONY-X TESTS
int			game_render(t_cubd *cub3D);
char		**generate_map(char *path);
t_window	get_window_size(char **map);
t_window	get_window(t_map *map);
int			render_rect(t_cubd *cub3d, t_rectangle *rect);
void		render_player(t_cubd *cub3d, t_player *player);
void		init_player(t_cubd *cub3d, t_player *player);

//RECTANGLE
void		img_pix_put(t_img *img, int x, int y, int color);
t_rectangle	*create_rect(int x, int y, int width, int height);
void		set_color_rect(t_rectangle *rect, int color);
int			draw_rect(t_img *img, t_rectangle *rect);
void		create_image(t_cubd *cub3d, t_img *img, int width, int height);
void		render_image_to_window(t_cubd *cub3d, t_img *img, int x, int y);

int			draw_line(t_cubd *cub3d, t_line *line);
void		move_player_events(t_cubd *cub3d, t_player *player, int key);

int			key_up(int key, t_cubd *cub3d);
int			key_down(int key, t_cubd *cub3d);


void		cast_all_rays(t_cubd *cub3d, t_player *player, int color);

// RAY FACING
int 		is_ray_facing_down(double angle);
int 		is_ray_facing_up(double angle);
int 		is_ray_facing_right(double angle);
int 		is_ray_facing_left(double angle);

//CALCULATE COORDINATES
double		get_y_horizontal_intercept(t_player *player);
double		get_y_vertical_intercept(t_player *player, double angle,
				double x_intercept);
double		get_x_horizontal_intercept(t_player *player, double angle,
				double y_intercept);
double		get_x_vertical_intercept(t_player *player);
void		increment_y_horizontal_intercept(double *y_intercept, double angle);
void		increment_x_vertical_intercept(double *x_intercept, double angle);

//CALCULATE STEPS
void		invert_y_vertical_step(double *y_step, double angle);
void		invert_x_vertical_step(double *x_step, double angle);
void		invert_x_horizontal_step(double *x_step, double angle);
void		invert_y_horizontal_step(double *y_step, double angle);
//UTILS

void		normalize_angle(double *angle);
int			is_inside_map(t_window window, double new_x, double new_y);
int			has_wall_at(char **map, double new_x, double new_y, t_cubd *cub3d);


//UTILS RAYS
t_line		*draw_ray(t_cubd *cub3d, double end_x, double end_y, int color);
double		calculate_distance_between_points(double x1, double y1,
			double x2, double y2);

#endif


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:16:51 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/04/23 16:43:06 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_window
{
	void	*win_ptr;
	int		width;
	int		height;
}	t_window;

typedef struct s_image
{
	void	*addr;
	int		width;
	int		height;
	int		x;
	int		y;
}	t_image;



typedef struct s_rectangle
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rectangle;

typedef struct s_line
{
    int     begin_x;
    int     begin_y;
    int     end_x;
    int     end_y;
    int     color;
    int     pixels;
    int   delta_x;
    int   delta_y;
    double   pixel_x;
    double   pixel_y;
}   t_line;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_game
{
	void		*mlx_ptr;
	char		**map;
	int			moves;
	int			collectibles;
	t_window	window;
	t_image		wall;
	t_image		space;
	t_image		tux;
	t_image		coin;
	t_image		door;
	t_img		img;
	t_img		img2;
}	t_game;

typedef struct s_file
{
	char	*name;
	int		fd;
}	t_file;

typedef struct s_map_dimensions
{
	int		columns;
	int		rows;
}	t_map_dimensions;

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
	int		alpha;
	char	*color_str;
}	t_color;

typedef struct s_map
{
	t_map_dimensions	dimensions;
	t_list				*map_list;
	char				**map_matrix;
	t_file				map_file;
	char				*no_file;
	char				*so_file;
	char				*we_file;
	char				*ea_file;
	t_color				floor_color;
	t_color				ceiling_color;
}	t_map;

typedef struct s_player
{
	double	x;
	double	y;
	double	width;
	double	height;
	int		turn_direction;
	int		walk_direction;
	double	rotation_angle;
	double	walk_speed;
	double	turn_speed;
	t_line	*line;
}	t_player;

typedef struct s_cubd
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	map;
	t_game	*game;
	t_player *player;
}	t_cubd;



#endif

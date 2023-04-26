/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:16:51 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/04/25 22:40:02 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_rectangule
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rectangule;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_file
{
	char	*name;
	int		fd;
}	t_file;

typedef struct s_cord
{
	int	x;
	int	y;
}	t_cord;

typedef struct s_map_dimensions
{
	int		columns;
	int		rows;
	int		col_offset;
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
	int					found_player;
}	t_map;

typedef struct s_cubd
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	map;
}	t_cubd;

#endif

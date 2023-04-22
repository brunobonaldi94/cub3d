/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:16:51 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/04/22 17:21:17 by bbonaldi         ###   ########.fr       */
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

typedef struct s_map_dimensions
{
	int		columns;
	int		rows;
}	t_map_dimensions;

typedef struct s_map
{
	t_map_dimensions	dimensions;
	char				**map_matrix;
	t_file				map_file;
	char				*no_file;
	char				*so_file;
	char				*we_file;
	char				*ea_file;
	char				*floor_color;
	char				*ceiling_color;
}	t_map;

typedef struct s_cubd
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	map;
}	t_cubd;

#endif

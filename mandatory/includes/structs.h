/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:16:51 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/04/21 15:59:04 by bbonaldi         ###   ########.fr       */
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

typedef struct s_map
{
	int		columns;
	int		rows;
	char	**map_matrix;
	char	*map_file_path;
	char	*no_file_path;
	char	*so_file_path;
	char	*we_file_path;
	char	*ea_file_path;
	char	*floor_color;
	char	*ceil_color;
}	t_map;

typedef struct s_cub3D
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	map;
}	t_cub3D;

#endif

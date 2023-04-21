/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:07:35 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/04/21 16:39:43 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

//BOOLEANS
# define TRUE 1
# define FALSE 0

//TERMINAL COLORS
# define RED "\033[0;31m"
# define BLUE "\033[0;34m"
# define RESET "\033[0m"
# define BLACK "\033[0;30m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"

//SUCCESS ERROR CODES
# define SUCCESS_CODE 0
# define ERROR_CODE 1
# define MLX_ERROR 1
# define MLX_ERROR_MESSAGE "MLX Error: There was an error in Minilibx Library!"
# define INVALID_ARGS_MESSAGE ""

//KEY EVENTS
# define KEY_PRESS_EVENT 2
# define DESTROY_NOTIFY_EVENT 17
# define KEY_SCAPE 0xff1b
# define KEY_W 0x0077
# define KEY_A 0x0061
# define KEY_S 0x0073
# define KEY_D 0x0064
# define KEY_LEFT 0xFF51
# define KEY_UP 0xFF52
# define KEY_RIGHT 0xFF53
# define KEY_DOWN 0xFF54

//PIXEL COLORS
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define WHITE_PIXEL 0xFFFFFF

//
# define TILE_SIZE 32
# define GAME_NAME "Cub3D - bbonaldi & sjhony-x"
# define MINIMAP_SCALE 1
# define UNINITIALIZED_FD -2

#endif

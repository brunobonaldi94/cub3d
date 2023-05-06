/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:07:35 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/04 22:00:24 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

//LIMITS
# define INT_MAX 2147483647
# define INT_MIN -2147483648

//DEBUG
# define DEBUG TRUE

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
# define INVALID_ARGS_MESSAGE "You must run cub3D with one map!"
# define MAP_IS_NOT_VALID_MESSAGE "File must have .cub extension \
or does not exist"
# define EMPTY_LINE_MESSAGE "Map must not have empty lines!"
# define NOT_ALLOW_CHARACTER_MESSAGE "Map can only contain NSEW01 and space"
# define MAP_PROPERTY_MISSING_MESSAGE "It's missing map property"
# define WRONG_MAP_DIMENSIONS_MESSAGE "Map dimensions are not correct!"
# define MAP_MUST_START_WITH_PROPERTIES_MESSAGE "Map must start with map \
properties"
# define WRONG_TEXTURE_PATH_MESSAGE "Wrong texture file path or invalid \
extension (it must be .xpm)"
# define DUPLICATED_PROPERTY_MESSAGE "Duplicated map property!"
# define NO_COLOR_SET_MESSAGE "No color set for floor or ceiling!"
# define WRONG_COLOR_SET_MESSAGE "Color must be at RGB format for \
floor or ceiling!"
# define PLAYER_ERROR_MESSAGE "It must have one Player position!"
# define MAP_TOO_BIG_MESSAGE "Map is too big!"
# define PLAYER_MUST_BE_INSIDE_MAP_MESSAGE "Player must be inside map!"

//KEY EVENTS
# define KEY_DOWN_EVENT 2
# define KEY_UP_EVENT 3
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
# define BLACK_PIXEL 0x000000
# define YELLOW_PIXEL 0xFFFF00
# define BLUE_PIXEL 0X0000FF

//GAME PROPERTIES
# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720
# define TILE_SIZE 64
# define GAME_NAME "Cub3D - bbonaldi & sjhony-x"
# define MINIMAP_SCALE 0.3

//MAP PROPERTIES
# define CUB_EXTENSION ".cub"
# define XPM_EXTENSION ".xpm"
# define UNINITIALIZED_FD -2
# define WHITE_SPACE " \t\r\n\v"
# define ALLOWED_MAP_CHARS "01NSEW \t\r\v"
# define ALLOWED_MAP_CHARS_NO_WHT_SPC "01NSEW"
# define PLAYER_CHAR "NSEW"
# define SOUTH_PROP "SO "
# define NORTH_PROP "NO "
# define EAST_PROP "EA "
# define WEST_PROP "WE "
# define FLOOR_PROP "F "
# define CEILING_PROP "C "
# define WALL_CHAR '1'
# define EMPTY_CHAR '0'

// CONSTANTS TO CALCULATIONS
# define PI 3.14159265
# define TWO_PI 6.28318530
// FOV_ANGLE = (60 * (PI / 180))
# define FOV_ANGLE 1.0471975511965976

# define NUM_RAYS WINDOW_WIDTH

# define RAY_LENGHT 60

#endif

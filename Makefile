# ==============================================================================
# PATH
# ==============================================================================

MANDATORY		:= ./mandatory
BONUS			:= ./bonus

LIBFT_PATH		:= ./libft
LIBFT_FULL_PATH = $(LIBFT_PATH)/libft.a

GAME_INIT				:= $(MANDATORY)/game_init
ERROR_HANDLER			:= $(MANDATORY)/error_handler
GAME_EVENTS				:= $(MANDATORY)/game_events
GAME_EXIT				:= $(MANDATORY)/game_exit
MAP_VALIDATION			:= $(MANDATORY)/map_validation
PLAYER					:= $(MANDATORY)/player
RAYCASTING				:= $(MANDATORY)/raycasting
WALLS					:= $(MANDATORY)/walls
GAME					:= $(MANDATORY)/game
DEBUG					:= $(MANDATORY)/debug

GAME_INIT_BONUS			:= $(BONUS)/game_init
ERROR_HANDLER_BONUS		:= $(BONUS)/error_handler
GAME_EVENTS_BONUS		:= $(BONUS)/game_events
GAME_EXIT_BONUS			:= $(BONUS)/game_exit
MAP_VALIDATION_BONUS	:= $(BONUS)/map_validation
PLAYER_BONUS			:= $(BONUS)/player
RAYCASTING_BONUS		:= $(BONUS)/raycasting
WALLS_BONUS				:= $(BONUS)/walls
GAME_BONUS				:= $(BONUS)/game
DEBUG_BONUS				:= $(BONUS)/debug
# ==============================================================================
# VARIABLES
# ==============================================================================
NAME			:=	cub3D
NAME_BONUS		:=	cub3D_bonus
CC				:=	cc
CFLAGS			:=	-g3 -Wall -Werror -Wextra -no-pie
MAKE			:=	make

INCLUDES_USR	:= -I./usr/include
INCLUDES		:= -I$(LIBFT_PATH)/includes -I$(MANDATORY)/includes
INCLUDES_BONUS	:= -I$(LIBFT_PATH)/includes -I$(BONUS)/includes

LIBRARY_MLX_PATH = -L/usr/lib -lmlx -lXext -lX11 -lm -lz

SRCS	:=		$(MANDATORY)/cub3D.c \
				$(GAME)/game.c $(GAME)/minimap.c \
				$(GAME_INIT)/game_init.c $(GAME_INIT)/game_init_utils.c \
				$(GAME_INIT)/images_init.c \
				$(ERROR_HANDLER)/error_handler.c \
				$(GAME_EVENTS)/game_events.c \
				$(GAME_EXIT)/game_exit.c $(GAME_EXIT)/game_exit_utils.c \
				$(MAP_VALIDATION)/map_validation.c $(MAP_VALIDATION)/file_helpers.c \
				$(MAP_VALIDATION)/map_validation_utils.c $(MAP_VALIDATION)/map_validation_utils_II.c \
				$(MAP_VALIDATION)/map_properties_utils.c $(MAP_VALIDATION)/map_content_utils.c \
				$(MAP_VALIDATION)/map_content_utils_II.c $(MAP_VALIDATION)/map_properties_utils_II.c \
				$(MAP_VALIDATION)/map_loaders.c \
				$(PLAYER)/map_utils.c $(PLAYER)/rectangle.c $(PLAYER)/player.c \
				$(PLAYER)/line.c $(PLAYER)/render_player.c $(PLAYER)/player_utils.c\
				$(PLAYER)/graphics.c $(PLAYER)/images_utils.c \
				$(RAYCASTING)/calculate_rays.c $(RAYCASTING)/ray_facing.c \
				$(RAYCASTING)/calculate_vertical_coordinates.c  $(RAYCASTING)/calculate_horizontal_coordinates.c \
				$(RAYCASTING)/calculate_steps.c $(RAYCASTING)/ray_utils.c $(RAYCASTING)/render_rays.c \
				$(RAYCASTING)/vertical_utils.c $(RAYCASTING)/horizontal_utils.c  $(RAYCASTING)/cast_rays.c\
				$(WALLS)/walls.c $(WALLS)/wall_utils.c $(WALLS)/calc_dist_wall.c \
				$(DEBUG)/debug.c

SRCS_BONUS	:=	$(BONUS)/cub3D_bonus.c \
				$(GAME_BONUS)/game_bonus.c $(GAME_BONUS)/minimap_bonus.c \
				$(GAME_INIT_BONUS)/game_init_bonus.c $(GAME_INIT_BONUS)/game_init_utils_bonus.c \
				$(GAME_INIT_BONUS)/images_init_bonus.c \
				$(ERROR_HANDLER_BONUS)/error_handler_bonus.c \
				$(GAME_EVENTS_BONUS)/game_events_bonus.c \
				$(GAME_EXIT_BONUS)/game_exit_bonus.c $(GAME_EXIT_BONUS)/game_exit_utils_bonus.c \
				$(MAP_VALIDATION_BONUS)/map_validation_bonus.c $(MAP_VALIDATION_BONUS)/file_helpers_bonus.c \
				$(MAP_VALIDATION_BONUS)/map_validation_utils_bonus.c $(MAP_VALIDATION_BONUS)/map_validation_utils_II_bonus.c \
				$(MAP_VALIDATION_BONUS)/map_properties_utils_bonus.c $(MAP_VALIDATION_BONUS)/map_content_utils_bonus.c \
				$(MAP_VALIDATION_BONUS)/map_content_utils_II_bonus.c $(MAP_VALIDATION_BONUS)/map_properties_utils_II_bonus.c \
				$(MAP_VALIDATION_BONUS)/map_loaders_bonus.c \
				$(PLAYER_BONUS)/map_utils_bonus.c $(PLAYER_BONUS)/rectangle_bonus.c $(PLAYER_BONUS)/player_bonus.c \
				$(PLAYER_BONUS)/line_bonus.c $(PLAYER_BONUS)/render_player_bonus.c $(PLAYER_BONUS)/player_utils_bonus.c\
				$(PLAYER_BONUS)/graphics_bonus.c $(PLAYER_BONUS)/images_utils_bonus.c \
				$(RAYCASTING_BONUS)/calculate_rays_bonus.c $(RAYCASTING_BONUS)/ray_facing_bonus.c \
				$(RAYCASTING_BONUS)/calculate_vertical_coordinates_bonus.c  $(RAYCASTING_BONUS)/calculate_horizontal_coordinates_bonus.c \
				$(RAYCASTING_BONUS)/calculate_steps_bonus.c $(RAYCASTING_BONUS)/ray_utils_bonus.c $(RAYCASTING_BONUS)/render_rays_bonus.c \
				$(RAYCASTING_BONUS)/vertical_utils_bonus.c $(RAYCASTING_BONUS)/horizontal_utils_bonus.c  $(RAYCASTING_BONUS)/cast_rays_bonus.c\
				$(WALLS_BONUS)/walls_bonus.c $(WALLS_BONUS)/wall_utils_bonus.c $(WALLS_BONUS)/calc_dist_wall_bonus.c \
				$(DEBUG_BONUS)/debug_bonus.c

OBJS		:=	$(SRCS:.c=.o)

OBJS_BONUS	:=	$(SRCS_BONUS:.c=.o)

# ==============================================================================
# COLORS
# ==============================================================================

GREEN		:=	\033[1;32m
RED			:=	\033[1;31m
WHT			:=	\033[1;37m
EOC			:=	\033[1;0m

# ==============================================================================
# RECIPES
# ==============================================================================

define COMPILE_DONE
 ____ ____ ____ ____ ____
||C |||U |||B |||3 |||D ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|
endef
export COMPILE_DONE

all:		$(NAME)

bonus:		$(NAME_BONUS)

%.o:		%.c
			@$(CC) $(CFLAGS) $(INCLUDES_USR) $(INCLUDES) -c $< -o $@

%_bonus.o:		%_bonus.c
			@$(CC) $(CFLAGS) $(INCLUDES_USR) $(INCLUDES_BONUS) -c $< -o $@

$(NAME):		$(LIBFT_FULL_PATH) $(OBJS)
				@echo "$(WHT)Compiling Cub3D...$(EOC)"
				@$(CC) $(CFLAGS) $(OBJS) $(LIBRARY_MLX_PATH) $(LIBFT_FULL_PATH) -o $(NAME)
				@echo "$(GREEN)Cub3D build completed.$(EOC)"
				@tput setaf 5
				@echo "$$COMPILE_DONE"

$(NAME_BONUS):	$(LIBFT_FULL_PATH) $(OBJS_BONUS)
				@echo "$(WHT)Compiling Cub3D bonus...$(EOC)"
				@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBRARY_MLX_PATH) $(LIBFT_FULL_PATH) -o $(NAME_BONUS)
				@\cp $(NAME_BONUS) $(NAME)
				@echo "$(GREEN)Cub3D build completed.$(EOC)"
				@tput setaf 5
				@echo "$$COMPILE_DONE"

$(LIBFT_FULL_PATH):
			@$(MAKE) -C libft

clean:
			@echo "$(WHT)Removing .o files...$(EOC)"
			@rm -f $(OBJS) $(OBJS_BONUS) $(MLX_LINUX_LIB)
			@$(MAKE) -C libft clean
			@echo "$(GREEN)Clean done.$(EOC)"

fclean:		clean
			@echo "$(WHT)Removing object- and binary -files...$(EOC)"
			@rm -f $(NAME) $(NAME_BONUS)
			@$(MAKE) -C libft fclean
			@echo "$(GREEN)Fclean done.$(EOC)"

re:			fclean all

valgrind:
			@valgrind -s --leak-check=full --show-leak-kinds=all \
			--track-origins=yes --trace-children=yes --log-fd=9 ./$(NAME) $(MAP) 9>memcheck.log

.PHONY:		all clean fclean re

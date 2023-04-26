# ==============================================================================
# PATH
# ==============================================================================

MANDATORY		:= ./mandatory

LIBFT_PATH		:= $(MANDATORY)/libft
LIBFT_FULL_PATH = $(LIBFT_PATH)/libft.a

GAME_INIT		:= $(MANDATORY)/game_init
ERROR_HANDLER	:= $(MANDATORY)/error_handler
GAME_EVENTS		:= $(MANDATORY)/game_events
GAME_EXIT		:= $(MANDATORY)/game_exit
MAP_VALIDATION	:= $(MANDATORY)/map_validation
PLAYER			:= $(MANDATORY)/player
DEBUG			:= $(MANDATORY)/debug
# ==============================================================================
# VARIABLES
# ==============================================================================
NAME			:=	cub3D
CC				:=	cc
CFLAGS			:=	-g3 -Wall -Werror -Wextra

INCLUDES_USR = -I./usr/include
INCLUDES = -I$(LIBFT_PATH)/includes -I$(MANDATORY)/includes

LIBRARY_MLX_PATH = -L/usr/lib -lmlx -lXext -lX11 -lm -lz

SRCS	:=	$(MANDATORY)/cub3D.c \
			$(MANDATORY)/test_minilibx.c \
			$(GAME_INIT)/game_init.c \
			$(ERROR_HANDLER)/error_handler.c \
			$(GAME_EVENTS)/game_events.c \
			$(GAME_EXIT)/game_exit.c $(GAME_EXIT)/game_exit_utils.c \
			$(MAP_VALIDATION)/map_validation.c $(MAP_VALIDATION)/file_helpers.c \
			$(MAP_VALIDATION)/map_validation_utils.c \
			$(MAP_VALIDATION)/map_properties_utils.c $(MAP_VALIDATION)/map_content_utils.c \
			$(PLAYER)/map.c $(PLAYER)/map_utils.c $(PLAYER)/rectangle.c $(PLAYER)/player.c \
			$(DEBUG)/debug.c

OBJS	:=	$(SRCS:.c=.o)

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

%.o:		%.c
			@$(CC) $(CFLAGS) $(INCLUDES_USR) $(INCLUDES) -c $< -o $@

$(NAME):	$(LIBFT_FULL_PATH) $(OBJS)
			@echo "$(WHT)Compiling Cub3D...$(EOC)"
			@$(CC) $(CFLAGS) $(OBJS) $(LIBRARY_MLX_PATH) -Llibft -lft -o $(NAME)
			@echo "$(GREEN)Cub3D build completed.$(EOC)"
			@tput setaf 5
			@echo "$$COMPILE_DONE"

$(LIBFT_FULL_PATH):
			@make -C libft

clean:
			@echo "$(WHT)Removing .o files...$(EOC)"
			@rm -f $(OBJS) $(MLX_LINUX_LIB)
			@make -C libft clean
			@echo "$(GREEN)Clean done.$(EOC)"

fclean:		clean
			@echo "$(WHT)Removing object- and binary -files...$(EOC)"
			@rm -f $(NAME)
			@make -C libft fclean
			@echo "$(GREEN)Fclean done.$(EOC)"

re:			fclean all

valgrind:
			@valgrind -s --leak-check=full --show-leak-kinds=all \
			--track-origins=yes --trace-children=yes --log-fd=9 ./$(NAME) 9>memcheck.log

valgrind_track:
			@valgrind -s --leak-check=full --show-leak-kinds=all \
			   --trace-children=yes --track-fds=yes --log-fd=9 ./$(NAME) 9>memcheck.log

.PHONY:		all clean fclean re

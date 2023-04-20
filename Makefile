# ==============================================================================
# PATH
# ==============================================================================
MLX_LINUX_PATH	:= ./mlx_linux
MLX_FULL_PATH	:= $(MLX_LINUX_PATH)/libmlx.a

LIBFT_PATH		:= ./libft
LIBFT_FULL_PATH = $(LIBFT_PATH)/libft.a

# ==============================================================================
# VARIABLES
# ==============================================================================
NAME			:=	cub3d
CC				:=	cc
CFLAGS			:=	-g3 -Wall -Werror -Wextra

INCLUDES_MLX_LINUX = -Imlx_linux
INCLUDES_USR = -I./usr/include
INCLUDES = -I$(LIBFT_PATH)/includes -I./includes

LIBRARY_MLX_PATH = -Lmlx_linux -lmlx_Linux -L/usr/lib
LIBRARIES_MLX = -lXext -lX11 -lm -lz

SRCS	:=	cub3d.c
			
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
			@$(CC) $(CFLAGS) $(INCLUDES_MLX_LINUX) $(INCLUDES_USR) $(INCLUDES) -c $< -o $@

$(NAME):	$(MLX_FULL_PATH) $(LIBFT_FULL_PATH) $(OBJS) 
			@echo "$(WHT)Compiling Cub3D...$(EOC)"
			@$(CC) $(CFLAGS) $(OBJS) $(LIBRARY_MLX_PATH) \
			$(INCLUDES_MLX_LINUX) $(LIBRARIES_MLX) -Llibft -lft -o $(NAME)
			@echo "$(GREEN)Cub3D build completed.$(EOC)"
			@tput setaf 5
			@echo "$$COMPILE_DONE"
			
$(LIBFT_FULL_PATH):
			@make -C libft

$(MLX_FULL_PATH):
			@tput setaf 5
			@echo COMPILING MLX
			@make -C $(MLX_LINUX_PATH)
			@cp $(MLX_FULL_PATH) ./

clean:
			@echo "$(WHT)Removing .o files...$(EOC)"
			@rm -f $(OBJS)
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

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/23 00:09:33 by bbonaldi          #+#    #+#              #
#    Updated: 2022/07/24 23:08:02 by bbonaldi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH_TEST	= tests
PATH_GAME	= ../
MAKE = make --no-print-directory
all:			m_both

m_both:			rm_core_files game permission norm all_maps_both
m_valid:		rm_core_files game permission norm all_maps_valid
m_invalid:		rm_core_files game permission norm all_maps_invalid

b_both:			rm_core_files game_bonus permission norm all_maps_both
b_valid:		rm_core_files game_bonus permission norm all_maps_valid
b_invalid:		rm_core_files game_bonus permission norm all_maps_invalid

m_single:		rm_core_files game permission norm single_map
b_single:		rm_core_files game_bonus permission norm single_map

game:
		@$(MAKE) fclean -C $(PATH_GAME)
		@$(MAKE) all -C $(PATH_GAME)

game_bonus:
		@$(MAKE) fclean -C $(PATH_GAME)
		@$(MAKE) bonus -C $(PATH_GAME)

permission:
		@chmod -R a+x *

all_maps_both:
	@./$(PATH_TEST)/all_maps.sh both

all_maps_valid:
	@./$(PATH_TEST)/all_maps.sh valid

all_maps_invalid:
	@./$(PATH_TEST)/all_maps.sh invalid

single_map:
	@./$(PATH_TEST)/single_map.sh $(MAP_PATH)

rm_core_files:
	@find . -type f -name '*.core.[0-9]*' -delete

norm:
	@./$(PATH_TEST)/check_norm_error.sh

.PHONY:		all m game game_bonus permission all_maps rm_core_files \
			all_maps_invalid all_maps_valid all_maps_both m_both m_valid \
			m_invalid b_both b_valid b_invalid count_of_leaks

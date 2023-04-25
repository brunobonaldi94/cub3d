# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 20:43:56 by harndt            #+#    #+#              #
#    Updated: 2023/04/24 22:26:17 by bbonaldi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ==============================================================================
# VARIABLES
# ==============================================================================

NAME	:=	libft.a
HEADER	:=	libft.h
CC		:=	cc
CFLAGS	:=	-Wall -Werror -Wextra -g3

# ==============================================================================
# LIBFT 1
# ==============================================================================

SRCS	:=	ft_atoi.c		ft_bzero.c		ft_calloc.c		\
			ft_isalnum.c	ft_isalpha.c	ft_isascii.c	\
			ft_isdigit.c	ft_isprint.c	ft_memchr.c		\
			ft_memcmp.c		ft_memcpy.c		ft_memmove.c	\
			ft_memset.c		ft_strchr.c		ft_strdup.c		\
			ft_strlcat.c	ft_strlcpy.c	ft_strlen.c		\
			ft_strncmp.c	ft_strnstr.c	ft_strrchr.c	\
			ft_tolower.c	ft_toupper.c	ft_strlen_no_white_space.c

# ==============================================================================
# LIBFT 2
# ==============================================================================

SRCS	+=	ft_substr.c		ft_strjoin.c	ft_strtrim.c	\
			ft_split.c		ft_itoa.c		ft_strmapi.c	\
			ft_striteri.c	ft_putchar_fd.c	ft_putstr_fd.c	\
			ft_putendl_fd.c	ft_putnbr_fd.c	ft_is_all_something.c


# ==============================================================================
# LIBFT BONUS
# ==============================================================================

SRCS	+=	ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c	\
			ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c	\
			ft_lstclear.c	ft_lstiter.c		ft_lstmap.c


# ==============================================================================
# GNL
# ==============================================================================

SRCS	+=	ft_get_next_line.c	ft_cpyline.c

# ==============================================================================
# FT_PRINTF
# ==============================================================================

SRCS	+=	ft_printf.c	ft_strnchr.c	ft_utoa_base.c		\
			ft_putstr.c	ft_putchar.c	ft_specifier_c.c	\
			ft_specifier_d.c	ft_specifier_p.c			\
			ft_specifier_percent.c	ft_specifier_s.c		\
			ft_specifier_u.c	ft_specifier_upperx.c		\
			ft_specifier_x.c

# ==============================================================================
# FDF
# ==============================================================================

SRCS	+=	ft_abs.c

# ==============================================================================
# MINITALK
# ==============================================================================

SRCS	+=	ft_isnum.c	ft_ternary.c

# ==============================================================================
# PUSH_SWAP
# ==============================================================================

SRCS	+=	ft_atol.c	ft_lstat.c	ft_lstdup_int.c	ft_lstsort.c	\
			ft_lstfind.c

# ==============================================================================
# MINISHELL
# =============================================================================

SRCS	+=	ft_free_ptr.c	ft_lstclear_not_free_content.c	ft_free_matrix.c \
			ft_strjoin_free.c	ft_strcmp.c	ft_strchr_pos.c	ft_replace_str.c \
			ft_count_char.c	ft_atoll.c

# ==============================================================================
# COLORS
# ==============================================================================

BLUE		:=	\033[1;36m
RED			:=	\033[1;31m
WHT			:=	\033[1;37m
EOC			:=	\033[1;0m

# ==============================================================================
# RECIPES
# ==============================================================================

OBJS	:=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			@echo "$(WHT)Compiling $(NAME)...$(EOC)"
			@ar -rc $(NAME) $(OBJS)
			@ranlib $(NAME)
			@echo "$(BLUE)$(NAME) build completed.$(EOC)"

%.o:		%.c $(HEADER)
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@echo "$(WHT)Removing .o files...$(EOC)"
			@rm -f $(OBJS)
			@echo "$(BLUE)LIBFT - Clean done.$(EOC)"

fclean:		clean
			@echo "$(WHT)Removing object- and binary -files...$(EOC)"
			@rm -f $(NAME)
			@echo "$(BLUE)LIBFT - Fclean done.$(EOC)"

re:			fclean all

.PHONY:		all, bonus, clean, fclean, re, .o

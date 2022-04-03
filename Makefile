NAME	:=	cub3d

SRCS	=	./srcs/display/display_ray.c \
				./srcs/engine/engine.c \
				./srcs/engine/raycasting.c \
				./srcs/errors/args_errors.c \
				./srcs/errors/map_errors.c \
				./srcs/errors/parsing_error_2.c \
				./srcs/errors/parsing_errors.c \
				./srcs/main.c \
				./srcs/memory/singleton.c \
				./srcs/moves/key_handler.c \
				./srcs/moves/moves.c \
				./srcs/parsing/check_args.c \
				./srcs/parsing/check_map.c \
				./srcs/parsing/check_specs.c \
				./srcs/parsing/everyone_is_in.c \
				./srcs/parsing/get_map.c \
				./srcs/parsing/open_textures.c \
				./srcs/parsing/parsing.c \
				./srcs/quit/quit.c \
				./srcs/utils/utils.c \

SRCS_BONUS = ./srcs_bonus/display/display_ray.c \
				./srcs_bonus/engine/door.c \
				./srcs_bonus/engine/engine.c \
				./srcs_bonus/engine/gun.c \
				./srcs_bonus/engine/init_raycasting.c \
				./srcs_bonus/engine/raycasting.c \
				./srcs_bonus/engine/sprites.c \
				./srcs_bonus/errors/args_errors.c \
				./srcs_bonus/errors/map_errors.c \
				./srcs_bonus/errors/parsing_error_2.c \
				./srcs_bonus/errors/parsing_errors.c \
				./srcs_bonus/main.c \
				./srcs_bonus/memory/singleton.c \
				./srcs_bonus/minimap/minimap.c \
				./srcs_bonus/moves/key_handler.c \
				./srcs_bonus/moves/mouse_handler.c \
				./srcs_bonus/moves/moves.c \
				./srcs_bonus/parsing/bonus_init.c \
				./srcs_bonus/parsing/check_args.c \
				./srcs_bonus/parsing/check_map.c \
				./srcs_bonus/parsing/check_specs.c \
				./srcs_bonus/parsing/everyone_is_in.c \
				./srcs_bonus/parsing/get_map.c \
				./srcs_bonus/parsing/open_textures.c \
				./srcs_bonus/parsing/parsing.c \
				./srcs_bonus/quit/quit.c \
				./srcs_bonus/utils/sprite_list_tools.c \
				./srcs_bonus/utils/utils.c \

OBJS	=	${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}
CC		=	clang
FLAGS	=	-Wall -Werror -Wextra -fsanitize=address -g3
SYSTEM = $(shell uname)

ifeq (${SYSTEM}, Darwin)
_END=$'\x1b[0m
_BOLD=$'\x1b[1m
_UNDER=$'\x1b[4m
_REV=$'\x1b[7m
_GREY=$'\x1b[30m
_RED=$'\x1b[31m
_GREEN=$'\x1b[32m
_YELLOW=$'\x1b[33m
_BLUE=$'\x1b[34m
_PURPLE=$'\x1b[35m
_CYAN=$'\x1b[36m
_WHITE=$'\x1b[37m
endif

ifeq (${SYSTEM}, Linux)
_GREY=	$'\033[30m
_RED=	$'\033[31m
_GREEN=	$'\033[32m
_YELLOW=$'\033[33m
_BLUE=	$'\033[34m
_PURPLE=$'\033[35m
_CYAN=	$'\033[36m
_WHITE=	$'\033[37m
_END= $'\033[37m
endif

ifeq (${SYSTEM}, Darwin)
INCS = -I ./includes -I ./libft/includes -I ./mlx_mac
LIBC = -L ./mlx_mac -lmlx ./libft/libft.a
MLX_FLAGS = -Ofast -framework OpenGL -framework AppKit
MLX_USED = mlx_mac
endif

ifeq (${SYSTEM}, Linux)
INCS = -I ./includes -I ./libft/includes -I ./mlx
LIBC = ./mlx/libmlx.a ./libft/libft.a
MLX_FLAGS	=	-L./mlx -lmlx -lX11 -lbsd -lXext -lm
MLX_USED = mlx
endif

all:		${NAME}

.c.o:
			@printf "%-15s ${_YELLOW}${_BOLD}$<${_END}...\n" "Compiling"
			@${CC} ${FLAGS} -Ofast ${INCS} -c $< -o $@

${NAME}:	${OBJS}
			@printf "%-15s ${_CYAN}${_BOLD}libft${_END}...\n" "Compiling"
			@${MAKE} -C libft >/dev/null
			@printf "%-15s ${_CYAN}${_BOLD}${MLX_USED}${_END}...\n" "Compiling"
			@${MAKE} -C ${MLX_USED} >/dev/null 2>&1
			@printf "%-15s ${_PURPLE}${_BOLD}${NAME}${_END}...\n" "Compiling"
			@${CC} ${FLAGS} ${INCS} ${MLX_FLAGS} -o ${NAME} ${OBJS} ${LIBC}
			@printf "\n${_GREEN}${_BOLD}Compilation done !${_END}\n"

bonus:		${OBJS_BONUS}
			@printf "%-15s ${_CYAN}${_BOLD}libft${_END}...\n" "Compiling"
			@${MAKE} -C libft >/dev/null
			@printf "%-15s ${_CYAN}${_BOLD}${MLX_USED}${_END}...\n" "Compiling"
			@${MAKE} -C ${MLX_USED} >/dev/null 2>&1
			@printf "%-15s ${_PURPLE}${_BOLD}${NAME}${_END}...\n" "Compiling"
			@${CC} ${FLAGS} ${INCS} ${MLX_FLAGS} -o ${NAME} ${OBJS_BONUS} ${LIBC}
			@printf "\n${_GREEN}${_BOLD}Compilation done !${_END}\n"

clean:		
			@printf "%-15s ${_RED}${_BOLD}libft binary files${_END}...\n" "Deleting"
			@${MAKE} -C libft clean >/dev/null
			@printf "%-15s ${_RED}${_BOLD}mlx binary files${_END}...\n" "Deleting"
			@${MAKE} -C ${MLX_USED} clean >/dev/null
			@printf "%-15s ${_RED}${_BOLD}${NAME} binary files${_END}...\n" "Deleting"
			@rm -f ${OBJS} ${OBJS_BONUS}


fclean:		clean
			@printf "%-15s ${_RED}${_BOLD}libft librairy${_END}...\n" "Deleting"
			@${MAKE} -C libft fclean >/dev/null
			@printf "%-15s ${_RED}${_BOLD}${NAME}${_END}...\n" "Deleting"
			@rm -f ${NAME}

re:			fclean all

.PHONY:		all fclean clean all bonus

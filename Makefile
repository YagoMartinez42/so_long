NAME	:= so_long
LFTDIR  := libft
LIBFT	:= libft.a
CC		:= gcc
VPATH	:= src bonus_src
CFLAGS	:= -Wall -Wextra -Werror
RM		:= rm -rf
SRC		:= so_long.c so_long_load.c so_long_validation.c so_long_map_utils.c \
			so_long_utility_hooks.c so_long_play.c so_long_memory_clear.c
BNSRC	:= so_long_bonus.c so_long_load_bonus.c so_long_validation_bonus.c \
			so_long_map_utils_bonus.c so_long_utility_hooks_bonus.c \
			so_long_play_bonus.c so_long_memory_clear_bonus.c \
			so_long_img_load_bonus.c so_long_animations_bonus.c 
OBJ		:= ${SRC:.c=.o}
BNOBJ	:= ${BNSRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ} ${LIBFT}
	${CC} ${OBJ} ${LIBFT} -Imlx -lmlx -framework OpenGL \
		-framework AppKit -o ${NAME}

bonus: ${BNOBJ} ${LIBFT}
	${CC} ${BNOBJ} ${LIBFT} -Imlx -lmlx -framework OpenGL \
		-framework AppKit -o so_long_bonus

${LIBFT}:
	cd ${LFTDIR} && make all
	cd ${LFTDIR} && mv ${LIBFT} ..


clean:
	${RM} ${OBJ} ${BNOBJ}
	cd ${LFTDIR} &&	make clean

fclean: clean
	${RM} ${NAME}
	${RM} ${NAME}
	${RM} ${LIBFT}

re: fclean all

.PHONY:	all clean fclean re bonus

NAME	:= so_long
BNNAME	:= so_long_bonus
LFTDIR  := libft
LIBFT	:= libft.a
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror -Iminilibx-linux
MLXFLG	:= -lmlx -lXext -lX11 -Lminilibx-linux -lm
MLXDIR	:= minilibx-linux
MLXLIB	:= minilibx-linux/libmlx.a
RM		:= rm -rf
SRC		:=	src/so_long.c \
			src/so_long_load.c \
			src/so_long_validation.c \
			src/so_long_map_utils.c \
			src/so_long_utility_hooks.c \
			src/so_long_play.c \
			src/so_long_memory_clear.c
BNSRC	:=	bonus_src/so_long_bonus.c \
			bonus_src/so_long_load_bonus.c \
			bonus_src/so_long_validation_bonus.c \
			bonus_src/so_long_map_utils_bonus.c \
			bonus_src/so_long_utility_hooks_bonus.c \
			bonus_src/so_long_play_bonus.c \
			bonus_src/so_long_memory_clear_bonus.c \
			bonus_src/so_long_img_load_bonus.c \
			bonus_src/so_long_animations_bonus.c 
OBJ		:= ${SRC:.c=.o}
BNOBJ	:= ${BNSRC:.c=.o}

all: ${NAME}

${LIBFT}:
	cd ${LFTDIR} && make all
	cd ${LFTDIR} && mv ${LIBFT} ..

${MLXLIB}:
	make -C ${MLXDIR}

${NAME}: ${OBJ} ${LIBFT} ${MLXLIB}
	${CC} ${OBJ} ${LIBFT} ${CFLAGS} ${MLXFLG} -o ${NAME}

${BNNAME}: ${BNOBJ} ${LIBFT} ${MLXLIB}
	${CC} ${BNOBJ} ${LIBFT} ${CFLAGS} ${MLXFLG} -o ${BNNAME}

bonus: ${BNNAME}

clean:
	${RM} ${OBJ} ${BNOBJ}
	cd ${LFTDIR} &&	make clean
	cd ${MLXDIR} &&	make clean

fclean: clean
	${RM} ${NAME}
	${RM} ${BNNAME}
	${RM} ${LIBFT}
	${RM} ${MLXLIB}

re: fclean all

.PHONY:	all clean fclean re bonus

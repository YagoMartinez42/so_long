NAME	:= so_long
BNNAME	:= so_long_bonus
LFTDIR  := libft
LIBFT	:= libft.a
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror
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

${NAME}: ${OBJ} ${LIBFT}
	${CC} ${OBJ} ${LIBFT} -Imlx -lmlx -framework OpenGL \
		-framework AppKit -o ${NAME}

${BNNAME}: ${BNOBJ} ${LIBFT}
	${CC} ${BNOBJ} ${LIBFT} -Imlx -lmlx -framework OpenGL \
		-framework AppKit -o so_long_bonus

bonus: ${BNNAME}

clean:
	${RM} ${OBJ} ${BNOBJ}
	cd ${LFTDIR} &&	make clean

fclean: clean
	${RM} ${NAME}
	${RM} ${BNNAME}
	${RM} ${LIBFT}

re: fclean all

.PHONY:	all clean fclean re bonus

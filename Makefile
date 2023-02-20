NAME	:= so_long
LFTDIR  := libft
LIBFT	:= libft.a
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror
RM		:= rm -rf
SRC		:= so_long.c so_long_load.c so_long_validation.c so_long_map_utils.c \
			so_long_utility_hooks.c so_long_play.c
OBJ		:= ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ} ${LIBFT}
	${CC} ${OBJ} ${LFTDIR}/${LIBFT} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}

${LIBFT}:
	cd ${LFTDIR} && make all

clean:
	${RM} ${OBJ}
	cd ${LFTDIR} &&	make clean

fclean: clean
	${RM} ${NAME}
	${RM} ${LIBFT}

re: fclean all

.PHONY:	all clean fclean re bonus

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samartin <samartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 14:33:37 by samartin          #+#    #+#              #
#    Updated: 2023/03/18 16:39:55 by samartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= libft.a
BASE	:= ft_base.a
LISTS	:= ft_lists.a
FILEM	:= ft_file_m.a
PRINT	:= ft_print.a
MATH	:= ft_math.a
CC		:= gcc
AR		:= ar -crs
CFLAGS	:= -Wall -Wextra -Werror
RM		:= rm -rf
SRC		:=	ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_itoab.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_realloc.c \
			ft_split.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strcpy.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c 
SRCLSTS	:=	lists/ft_lstadd_back.c \
			lists/ft_lstclear.c \
			lists/ft_lstadd_front.c \
			lists/ft_lstdelone.c \
			lists/ft_lstiter.c \
			lists/ft_lstlast.c \
			lists/ft_lstmap.c \
			lists/ft_lstnew.c \
			lists/ft_lstremove_if.c \
			lists/ft_lstsize.c \
			lists/ft_lstsort.c
SRCFLM	:= 	filem/get_next_line.c \
			filem/get_next_line_utils.c
SRCPRNT :=	print/ft_printf.c \
			print/ft_printf_alpha_utils.c \
			print/ft_printf_dec_utils.c \
			print/ft_printf_hex_utils.c \
			print/ft_print_memory.c
SRCMATH := 	math/ft_math.c
OBJ		:= ${SRC:.c=.o}
OBJLSTS	:= ${SRCLSTS:.c=.o}
OBJFLM	:= ${SRCFLM:.c=.o}
OBJPRNT	:= ${SRCPRNT:.c=.o}
OBJMATH := ${SRCMATH:.c=.o}


all: ${OBJ} ${OBJLSTS} ${OBJFLM} ${OBJPRNT} ${OBJMATH}
	${AR} ${NAME} $^

${BASE}: ${OBJ}
	${AR} ${BASE} $^

${LISTS}: ${OBJLSTS}
	${AR} ${LISTS} $^

${FILEM}: ${OBJFLM}
	${AR} ${FILEM} $^

${PRINT}: ${OBJ} ${OBJPRNT}
	${AR} ${PRINT} $^

${MATH}: ${OBJMATH}
	${AR} ${MATH} $^

clean:
	${RM} ${OBJ} ${OBJLSTS} ${OBJFLM} ${OBJPRNT} ${OBJMATH}

fclean: clean
	${RM} ${NAME} ${BASE} ${LISTS} ${FILEM} ${PRINT} ${MATH}

re: fclean all

.PHONY:	all clean fclean re bonus
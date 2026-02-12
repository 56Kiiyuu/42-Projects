NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I include

SRC =	src/main.c \
		src/utils.c \
		src/init_map.c \
		src/cleans_close.c \
		src/parse_map.c \
		src/render.c \
		src/move_player.c

OBJS = ${SRC:.c=.o}

LIBFT_PATH = lib/libft
MLX_PATH = lib/mlx
LIBFT = -L ${LIBFT_PATH} -lft
MLX	= -L ${MLX_PATH} -lmlx -Ilmlx -lXext -lX11 -lm

.c.o:
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		make -C ${LIBFT_PATH}
		make -C ${MLX_PATH}
		${CC} ${OBJS} ${LIBFT} ${MLX} -o ${NAME}

all:	${NAME}

clean:
		make -C ${LIBFT_PATH} clean
		make -C ${MLX_PATH} clean
		rm -f ${OBJS}

fclean: clean
		make -C ${LIBFT_PATH} fclean
		rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re

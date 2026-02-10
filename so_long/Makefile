NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src
PARSE_DIR = $(SRC_DIR)/parsing
RENDER_DIR = $(SRC_DIR)/render
GAME_DIR = $(SRC_DIR)/game

SRC_FILES = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/init.c \
	$(SRC_DIR)/utils.c \
	$(PARSE_DIR)/read_map.c \
	$(PARSE_DIR)/check_shape.c \
	$(PARSE_DIR)/check_content.c \
	$(PARSE_DIR)/check_walls.c \
	$(PARSE_DIR)/flood_fill.c \
	$(RENDER_DIR)/render_map.c \
	$(RENDER_DIR)/draw_tile.c \
	$(RENDER_DIR)/load_images.c \
	$(GAME_DIR)/hooks.c \
	$(GAME_DIR)/move_player.c \
	$(GAME_DIR)/collectibles.c \
	$(GAME_DIR)/win.c \
	$(GAME_DIR)/loop.c

MLX_DIR = ./minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
MLX_INC = -I $(MLX_DIR)
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
INC_DIRS = -I ./includes -I $(LIBFT_DIR) $(MLX_INC)

OBJS = $(SRC_FILES:.c=.o)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) $(INC_DIRS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) all

$(MLX):
	$(MAKE) -C $(MLX_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

INC_DIR = inc
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

OBJ_DIR = objs

SRCS = \
	srcs/commands/push.c \
	srcs/commands/reverse_rotate.c \
	srcs/commands/rotate.c \
	srcs/commands/min_on_top.c \
	srcs/commands/sort_stacks.c \
	srcs/commands/sort_three.c \
	srcs/commands/swap.c \
	srcs/push_swap/handle_errors.c \
	srcs/push_swap/init_a_to_b.c \
	srcs/push_swap/init_b_to_a.c \
	srcs/push_swap/main.c \
	srcs/push_swap/split.c \
	srcs/push_swap/stack_init.c \
	srcs/push_swap/stack_utils.c

OBJS = $(SRCS:srcs/%.c=$(OBJ_DIR)/%.o)

RM = rm -rf

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(OBJ_DIR)/%.o: srcs/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR)/inc -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

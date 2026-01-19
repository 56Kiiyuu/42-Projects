NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

INC_DIR = inc
OBJ_DIR = objs

SRCS = \
	srcs/ft_atoi.c \
	srcs/ft_bzero.c \
	srcs/ft_calloc.c \
	srcs/ft_isalnum.c \
	srcs/ft_isalpha.c \
	srcs/ft_isascii.c \
	srcs/ft_isdigit.c \
	srcs/ft_isprint.c \
	srcs/ft_itoa.c \
	srcs/ft_lstadd_back.c \
	srcs/ft_lstadd_front.c \
	srcs/ft_lstclear.c \
	srcs/ft_lstdelone.c \
	srcs/ft_lstiter.c \
	srcs/ft_lstlast.c \
	srcs/ft_lstmap.c \
	srcs/ft_lstnew.c \
	srcs/ft_lstsize.c \
	srcs/ft_memchr.c \
	srcs/ft_memcmp.c \
	srcs/ft_memcpy.c \
	srcs/ft_memmove.c \
	srcs/ft_memset.c \
	srcs/ft_printchar.c \
	srcs/ft_printf.c \
	srcs/ft_printhex.c \
	srcs/ft_printnbr.c \
	srcs/ft_printper.c \
	srcs/ft_printptr.c \
	srcs/ft_printstr.c \
	srcs/ft_printuint.c \
	srcs/ft_putchar_fd.c \
	srcs/ft_putendl_fd.c \
	srcs/ft_putnbr_fd.c \
	srcs/ft_putstr_fd.c \
	srcs/ft_split.c \
	srcs/ft_strchr.c \
	srcs/ft_strdup.c \
	srcs/ft_striteri.c \
	srcs/ft_strjoin.c \
	srcs/ft_strlcat.c \
	srcs/ft_strlcpy.c \
	srcs/ft_strlen.c \
	srcs/ft_strmapi.c \
	srcs/ft_strncmp.c \
	srcs/ft_strnstr.c \
	srcs/ft_strrchr.c \
	srcs/ft_strtrim.c \
	srcs/ft_substr.c \
	srcs/ft_tolower.c \
	srcs/ft_toupper.c

OBJS = $(SRCS:srcs/%.c=$(OBJ_DIR)/%.o)

AR = ar rcs
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: srcs/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: [kevlim] <[kevlim@student.42.fr]>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/30 13:56:15 by [kevlim]          #+#    #+#              #
#    Updated: 2025/09/30 16:52:47 by kevlim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

SRCS = srcs/ft_display_file.c
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I includes

all: $(NAME)

$(NAME): $(OBJS)
		cc $(CFLAGS) -o $(NAME) $(OBJS)

srcs/%.o: srcs/%.c
		cc $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
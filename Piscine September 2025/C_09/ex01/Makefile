# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: [kevlim] <[kevlim@student.42.fr]>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/29 14:48:45 by [kevlim]          #+#    #+#              #
#    Updated: 2025/09/29 15:07:03 by [kevlim]         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = srcs/ft_putchar.c \
	srcs/ft_strlen.c \
	srcs/ft_strcmp.c \
	srcs/ft_putstr.c \
	srcs/ft_swap.c

OFILES = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

.c.o:
	cc ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

$(NAME): ${OFILES}
	ar rcs ${NAME} ${OFILES}

all:	${NAME}

clean:
	rm -f ${OFILES}

fclean: clean
	rm -f ${NAME}

re:	fclean all

.PHONY: clean fclean re all

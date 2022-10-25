# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/19 16:07:36 by susong            #+#    #+#              #
#    Updated: 2022/10/25 11:22:17 by susong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex
SRCS	= src/pipex.c \
			src/parse.c \
			src/util_1.c \
			src/util_2.c \
			src/util_3.c
OBJS	= $(SRCS:.c=.o)
RM		= rm -f
CC		= gcc
HEADER  = include/pipex.h
CFLAGS	= -Wall -Wextra -Werror

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEADER}

$(NAME): ${OBJS}
	$(CC) -o $(NAME) $(OBJS)

all: $(NAME)

fclean: clean
	$(RM) $(NAME) $(bonus)

clean:
	$(RM) -f $(OBJS)

re: fclean all

.PHONY: all bonus clean fclean re .c.o

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/19 16:07:36 by susong            #+#    #+#              #
#    Updated: 2022/09/24 20:54:38 by susong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
SRCS	= 	src/so_long.c \
			# src/check_map.c \
			# src/check_map_util.c \
			# src/gnl.c \
			# src/gnl_2.c
OBJS	= $(SRCS:.c=.o)
RM		= rm -f
CC		= gcc
HEADER  = 	include/study.h \
			# include/so_long.h
# CFLAGS	= -Wall -Wextra -Werror

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEADER} -I mlx

$(NAME): ${OBJS}
	$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS)

all: $(NAME)

fclean: clean
	$(RM) $(NAME) $(bonus)

clean:
	$(RM) -f $(OBJS)

re: fclean all

.PHONY: all bonus clean fclean re .c.o

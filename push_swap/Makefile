# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/19 16:07:36 by susong            #+#    #+#              #
#    Updated: 2022/09/19 16:17:20 by susong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=   push_swap
SRCS	=	src/push_swap.c \
			src/parse.c
OBJS	= $(SRCS:.c=.o)
RM		= rm -f
CC		= gcc
HEADER  = include/push_swap.h
# CFLAGS	= -Wall -Wextra -Werror

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEADER}

$(NAME): ${OBJS}
	${CC} -o $(NAME) -g $(OBJS)

all: $(NAME)

fclean: clean
	$(RM) $(NAME) $(bonus)

clean:
	$(RM) -f $(OBJS)

re: fclean all

.PHONY: all bonus clean fclean re .c.o

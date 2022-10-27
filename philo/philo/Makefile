# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 13:52:45 by susong            #+#    #+#              #
#    Updated: 2022/10/25 13:53:13 by susong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo
SRCS	= src/philo.c

OBJS	= $(SRCS:.c=.o)
RM		= rm -f
CC		= gcc
HEADER  = include/philo.h
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

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/17 12:49:38 by susong            #+#    #+#              #
#    Updated: 2022/08/18 16:58:49 by susong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	ft_printf.c \
			srcs/print_function_1.c \
			srcs/print_function_2.c \
			Lib/Lib1.c

OBJS	=	ft_printf.o \
			print_function_1.o \
			print_function_2.o \
			Lib1.o

INCLUDE	=	inc/ft_printf.h

RM		= rm -f
LIBC	= ar -rcs
CC		= gcc
# CFLAGS	= -Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJS)

$(OBJS): $(SRCS) $(INCLUDE)
	${CC} -c $(SRCS)
	${LIBC} $(NAME) $(OBJS)
# 34번줄 ${CFLAGS} 넣기

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS)

test : re
	gcc $(NAME) test.c


re: fclean all

.PHONY: all clean fclean re

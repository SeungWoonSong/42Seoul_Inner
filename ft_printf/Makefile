# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/17 12:49:38 by susong            #+#    #+#              #
#    Updated: 2022/08/19 15:14:05 by susong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	ft_printf.c \
			srcs/print_function_1.c \
			srcs/print_function_2.c \
			srcs/print_function_3.c \
			Lib/Lib1.c


OBJS	=	ft_printf.o \
			print_function_1.o \
			print_function_2.o \
			print_function_3.o \
			Lib1.o

INCLUDE	=	inc/ft_printf.h

RM		= rm -f
LIBC	= ar -rcs
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJS)

$(OBJS): $(SRCS) $(INCLUDE)
	${CC} -c ${CFLAGS} $(SRCS)
	${LIBC} $(NAME) $(OBJS)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS)

re: fclean all

.PHONY: all clean fclean re

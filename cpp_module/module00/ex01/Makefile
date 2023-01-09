# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 09:25:35 by susong            #+#    #+#              #
#    Updated: 2023/01/09 10:43:04 by susong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	PhoneBook

SOURCE		=	main.cpp PhoneBook.cpp

OBJECT		=	$(SOURCE:.cpp=.o)

COMPILE		= 	c++

FLAGS		= 	-Wall -Wextra -Werror -std=c++98


all: $(NAME)

%.o: %.cpp
	$(COMPILE) $(FLAGS) -c $< -o $@

$(NAME): $(OBJECT)
	$(COMPILE) $(FLAGS) $(OBJECT) -o $(NAME)

clean:
	/bin/rm -f $(OBJECT)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 17:31:12 by yoda              #+#    #+#              #
#    Updated: 2024/05/16 03:57:50 by yoda             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
SRCS = main.cpp \
	PhoneBook.cpp \
	utils.cpp
CC = c++
VERSION = -std=c++98
CFLAGS = -Wall -Werror -Wextra
LEAKS = leaks -q $(NAME)

all: $(NAME)

leaks : fclean
	$(CC) $(VERSION) $(CFLAGS) $(SRCS) -o $(NAME) -D LEAKS=$(LEAKS)

$(NAME):
	$(CC) $(VERSION) $(CFLAGS) $(SRCS) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re leaks
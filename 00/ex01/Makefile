NAME = phonebook
SRCS = main.cpp phonebook_handler.cpp
CC = c++
VERSION = -std=c++98
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	$(CC) $(VERSION) $(CFLAGS) $(SRCS) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
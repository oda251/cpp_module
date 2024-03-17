NAME = megaphone
SRCS = megaphone.cpp
VERSION = -std=c++98
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	c++ -Wall -Werror -Wextra $(SRCS) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
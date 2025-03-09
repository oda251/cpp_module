NAME = convert
SRCS = main.cpp \
	SchalarConverter.cpp

CC = c++
VERSION = -std=c++98
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

leaks: fclean
	$(CC) $(VERSION) $(CFLAGS) $(SRCS) -o $(NAME) -g
	@valgrind --leak-check=full ./$(NAME)

$(NAME):
	$(CC) $(VERSION) $(CFLAGS) $(SRCS) -o $(NAME)

run: all
	@./$(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re run leaks

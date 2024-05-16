NAME = phonebook
SRCS = main.cpp \
	Contact.cpp \
	PhoneBook.cpp \
	utils.cpp
CC = c++
VERSION = -std=c++98
CFLAGS = -Wall -Werror -Wextra
LEAKS = leaks -q $(NAME)

all: $(NAME)

run: all
	./$(NAME)

leaks : fclean
	$(CC) $(VERSION) $(CFLAGS) $(SRCS) -o $(NAME) -D LEAKS=$(LEAKS)

$(NAME):
	$(CC) $(VERSION) $(CFLAGS) $(SRCS) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re leaks run
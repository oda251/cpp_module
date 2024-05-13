NAME = violence
SRCS = main.cpp \
	   HumanA.cpp \
	   HumanB.cpp \
	   Weapon.cpp
CC = c++
VERSION = -std=c++98
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

leaks: fclean
	$(CC) $(VERSION) $(CFLAGS) $(SRCS) -o $(NAME) -D LEAKS

$(NAME):
	$(CC) $(VERSION) $(CFLAGS) $(SRCS) -o $(NAME)

run: all
	./$(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re leaks

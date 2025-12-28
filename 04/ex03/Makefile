NAME = materia
SRCS = main.cpp \
	AMateria.cpp \
	Character.cpp \
	Cure.cpp \
	Ice.cpp \
	MateriaSource.cpp

CC = c++
VERSION = -std=c++98
CFLAGS = -Wall -Werror -Wextra
LEAKS = '"leaks -q $(NAME)"'

all: $(NAME)

leaks: fclean
	$(CC) $(VERSION) $(CFLAGS) $(SRCS) -o $(NAME) -D LEAKS=$(LEAKS)

$(NAME):
	$(CC) $(VERSION) $(CFLAGS) $(SRCS) -o $(NAME)

run: all
	./$(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re run leaks

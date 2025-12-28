NAME = sed
SRCS = main.cpp

CC = c++
VERSION = -std=c++98
CFLAGS = -Wall -Werror -Wextra

INFILE = ./test.cpp
OUTFILE = ./test.cpp.replace
NON_EXISTING_FILE = ./non_existing_file
EMPTY_FILE = ./empty.cpp
EMPTY_OUTFILE = ./empty.cpp.replace

all: $(NAME)

$(NAME):
	$(CC) $(VERSION) $(CFLAGS) $(SRCS) -o $(NAME)

test: all
	@rm -f $(OUTFILE)

	@echo "--- standard test ---"
	./$(NAME) $(INFILE) "abc" "[replaced]"
	@echo "--- output ---"
	@cat $(OUTFILE)
	@rm -f $(OUTFILE)

	@echo "--- empty s1 ---"
	./$(NAME) $(INFILE) "" "[replaced]"
	@echo "--- output ---"
	@cat $(OUTFILE)
	@rm -f $(OUTFILE)

	@echo "--- empty s2 ---"
	./$(NAME) $(INFILE) "abc" ""
	@echo "--- output ---"
	@cat $(OUTFILE)
	@rm -f $(OUTFILE)

	@echo "--- empty s1 and s2 ---"
	./$(NAME) $(INFILE) "" ""
	@echo "--- output ---"
	@cat $(OUTFILE)
	@rm -f $(OUTFILE)

	@rm -f $(EMPTY_OUTFILE)

	@echo "--- empty file ---"
	./$(NAME) $(EMPTY_FILE) "abc" "[replaced]"
	@echo "--- output ---"
	@cat $(EMPTY_OUTFILE)
	@rm -f $(EMPTY_OUTFILE)

	@echo "--- non existing file ---"
	./$(NAME) $(NON_EXISTING_FILE) "abc" "[replaced]"
	@rm -f $(OUTFILE)

run: all
	./$(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re run test

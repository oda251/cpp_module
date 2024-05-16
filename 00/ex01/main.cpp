#include "PhoneBook.hpp"
#include "utils.hpp"
#include <iostream>
#include <cstdlib>

__attribute__((destructor))
void    destructor(void)
{
	#ifdef LEAKS
	std::cout << "--- Destructor ---" << std::endl;
	system(LEAKS);
	#endif
}

int	main() {
	std::string input;
	PhoneBook phoneBook;

	while (1)
	{
		std::cout << "Enter a command: ";
		safe_cin(input);
		if (input == "ADD") {
			phoneBook.inputContact();
		} else if (input == "SEARCH") {
			phoneBook.searchContact();
		} else if (input == "EXIT") {
			std::cout << "EXIT" << std::endl;
			break;
		} else {
			std::cout << "Invalid command" << std::endl;
		}
	}
	return (0);
}

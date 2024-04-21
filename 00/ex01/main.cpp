#include "ex01.hpp"

int	main() {
	std::string input;
	PhoneBook phoneBook;

	while (1)
	{
		std::cout << "Enter a command: ";
		std::cin >> input;
		if (input == "ADD") {
			add_contact(&phoneBook);
		} else if (input == "SEARCH") {
			search_contact(&phoneBook);
		} else if (input == "EXIT") {
			std::cout << "EXIT" << std::endl;
			break;
		} else {
			std::cout << "Invalid command" << std::endl;
		}
	}
	return (0);
}

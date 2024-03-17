#include "ex01.hpp"

int main() {
	std::string input;
	PhoneBook phoneBook;

	while (1)
	{
		std::cout << "Enter a command: ";
		std::cin >> input;
		if (input == "ADD") {
			Contact *contact = new Contact();
			std::cout << "Enter first name: ";
			std::cin >> contact->firstName;
			std::cout << "Enter last name: ";
			std::cin >> contact->lastName;
			std::cout << "Enter nickname: ";
			std::cin >> contact->nickname;
			std::cout << "Enter phone number: ";
			std::cin >> contact->phoneNumber;
			std::cout << "Enter darkest secret: ";
			std::cin >> contact->darkestSecret;
			phoneBook.addContact(contact);
		} else if (input == "SEARCH") {
			int index;
			std::cout << "Enter index: ";
			std::cin >> index;
			phoneBook.serchContact(index);
		} else if (input == "EXIT") {
			break;
		}
	}
	return (0);
}

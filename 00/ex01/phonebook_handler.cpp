#include "ex01.hpp"

static bool	is_valid_phonenum_char(char c) {
	return std::isdigit(c) || c == '-' || c == '+' || c == '(' || c == ')';
}

static bool	is_valid_phonenumber(std::string phonenumber) {
	return std::all_of(phonenumber.begin(), phonenumber.end(), is_valid_phonenum_char);
}

static std::string	truncate(std::string str) {
	if (str.length() > 10) {
		str.resize(9);
		str.append(".");
	} else if (str.length() < 10) {
		str.insert(0, 10 - str.length(), ' ');
	}
	return str;
};

void	search_contact(PhoneBook *phoneBook) {
	int index;
	std::cout << "Enter index: ";
	std::cin >> index;

	Contact *contact = phoneBook->getContact(index);
	if (contact != NULL) {
		std::cout << "First name: " << truncate(contact->firstName) << "|" << std::endl;
		std::cout << "Last name: " << truncate(contact->lastName) << "|" << std::endl;
		std::cout << "Nickname: " << truncate(contact->nickname) << "|" << std::endl;
		std::cout << "Phone number: " << truncate(contact->phoneNumber) << "|" << std::endl;
		std::cout << "Darkest secret: " << truncate(contact->darkestSecret) << "|" << std::endl;
	} else {
		std::cout << "Contact not found" << std::endl;
	}
}

void	add_contact(PhoneBook *phoneBook) {
	Contact *contact = new Contact();
	std::cout << "Enter first name: ";
	std::cin >> contact->firstName;
	std::cout << "Enter last name: ";
	std::cin >> contact->lastName;
	std::cout << "Enter nickname: ";
	std::cin >> contact->nickname;
	std::cout << "Enter phone number: ";
	std::cin >> contact->phoneNumber;
	while (!is_valid_phonenumber(contact->phoneNumber)) {
		std::cout << "Invalid phone number.\nRe-enter: ";
		std::cin >> contact->phoneNumber;
	}
	std::cout << "Enter darkest secret: ";
	std::cin >> contact->darkestSecret;
	phoneBook->addContact(contact);
	std::cout << "SUCCESS" << std::endl;
}

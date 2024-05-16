#include "PhoneBook.hpp"
#include <iostream>
#include <limits>

int	PhoneBook::getNumberOfcontacts() {
	return _NumberOfcontacts;
};
void PhoneBook::addContact(Contact contact) {
	if (_NumberOfcontacts < 8) {
		contact.setIndex(_NumberOfcontacts);
		_contacts[_NumberOfcontacts] = contact;
		_NumberOfcontacts++;
	}
	else {
		for (int i = 0; i < _maxContacts - 1; i++) {
			_contacts[i] = _contacts[i + 1];
			_contacts[i].setIndex(i);
		}
		std::cout << "1" << std::endl;
		contact.setIndex(_maxContacts - 1);
		std::cout << "1" << std::endl;
		_contacts[_maxContacts - 1] = contact;
	}
};
Contact *PhoneBook::getContact(int index) {
	if (index < 0 || index >= _NumberOfcontacts) {
		return NULL;
	} else {
		return &_contacts[index];
	}
};

PhoneBook::PhoneBook() : _NumberOfcontacts(0) {
	for (int i = 0; i < 8; i++) {
		_contacts[i] = Contact();
	}
};
PhoneBook::~PhoneBook() {};

void	PhoneBook::inputContact() {
	Contact contact;
	std::string	input;
	contact.setIndex(_NumberOfcontacts);
	std::cout << "Enter first name: ";
	safe_cin(input);
	while (!contact.setFirstName(input)) {
		std::cout << "Invalid first name.\nRe-enter: " << std::endl;
		safe_cin(input);
	}
	std::cout << "Enter last name: ";
	safe_cin(input);
	while (!contact.setLastName(input)) {
		std::cout << "Invalid last name.\nRe-enter: " << std::endl;
		safe_cin(input);
	}
	std::cout << "Enter nickname: ";
	safe_cin(input);
	while (!contact.setNickname(input)) {
		std::cout << "Invalid nickname.\nRe-enter: " << std::endl;
		safe_cin(input);
	}
	std::cout << "Enter phone number: ";
	safe_cin(input);
	while (!contact.setPhoneNumber(input)) {
		std::cout << "Invalid phone number.\nRe-enter: " << std::endl;
		safe_cin(input);
	}
	std::cout << "Enter darkest secret: ";
	safe_cin(input);
	contact.setDarkestSecret(input);
	addContact(contact);
	std::cout << "SUCCESS" << std::endl;
}

void	PhoneBook::searchContact() {
	if (_NumberOfcontacts == 0) {
		std::cout << "No contacts registered" << std::endl;
		return;
	}
	displayContactHeader();
	for (int i=0; i<_NumberOfcontacts; i++) {
		_contacts[i].displayTrunced();
	}
	int index;
	std::cout << "Enter index: ";
	safe_cin_int(index);
	if (index < 0 || index >= _NumberOfcontacts) {
		std::cout << "Invalid index" << std::endl;
		return;
	} else {
		_contacts[index].display();
	}
}

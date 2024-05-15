/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:31:16 by yoda              #+#    #+#             */
/*   Updated: 2024/05/16 00:59:45 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <limits>

void PhoneBook::_addContact(Contact *contact) {
	if (_NumberOfcontacts < 8) {
		contact->index = _NumberOfcontacts;
		_contacts[_NumberOfcontacts] = contact;
		_NumberOfcontacts++;
	}
	else {
		delete _contacts[0];
		for (int i = 0; i < 7; i++) {
			_contacts[i]->index = i;
			_contacts[i] = _contacts[i + 1];
		}
		contact->index = 7;
		_contacts[7] = contact;
	}
};
Contact *PhoneBook::_getContact(int index) {
	if (index < 0 || index >= _NumberOfcontacts) {
		return NULL;
	} else {
		return _contacts[index];
	}
};

PhoneBook::PhoneBook() : _NumberOfcontacts(0) {
	for (int i = 0; i < 8; i++) {
		_contacts[i] = NULL;
	}
};
PhoneBook::~PhoneBook() {
	for (int i = 0; i < _NumberOfcontacts; i++) {
		delete _contacts[i];
	}
};
void	PhoneBook::searchContact() {
	if (_NumberOfcontacts == 0) {
		std::cout << "No _contacts registered" << std::endl;
		return;
	}
	Contact::displayHeader();
	for (int i=0; i<_NumberOfcontacts; i++) {
		_contacts[i]->displayTrunced();
	}
	int index;
	std::cout << "Enter index: ";
	std::cin >> index;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid index" << std::endl;
		return;
	} else if (index < 0 || index >= _NumberOfcontacts) {
		std::cout << "Invalid index" << std::endl;
		return;
	} else {
		_contacts[index]->display();
	}
}

void	PhoneBook::addContact() {
	Contact *contact = new Contact();
	contact->index = _NumberOfcontacts;
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
	_addContact(contact);
	std::cout << "SUCCESS" << std::endl;
}

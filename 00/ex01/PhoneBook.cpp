/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:31:16 by yoda              #+#    #+#             */
/*   Updated: 2024/05/14 04:43:04 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <limits>

void	PhoneBook::searchContact() {
	if (NumberOfcontacts == 0) {
		std::cout << "No contacts registered" << std::endl;
		return;
	}
	Contact::displayHeader();
	for (int i=0; i<NumberOfcontacts; i++) {
		contacts[i]->displayTrunced();
	}
	int index;
	std::cout << "Enter index: ";
	std::cin >> index;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid index" << std::endl;
		return;
	} else if (index < 0 || index >= NumberOfcontacts) {
		std::cout << "Invalid index" << std::endl;
		return;
	} else {
		contacts[index]->display();
	}
}

void	PhoneBook::addContact() {
	Contact *contact = new Contact();
	contact->index = NumberOfcontacts;
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

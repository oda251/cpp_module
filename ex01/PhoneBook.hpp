#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <string>
# include <iostream>
# include "Contact.hpp"

std::string truncate(std::string str) {
	if (str.length() > 10) {
		str.resize(9);
		str.append(".");
	}
	return str;
};

class PhoneBook {
	private:
		Contact	*contacts[8];
		int		NumberOfcontacts = 0;
	
	public:
		inline void addContact(Contact *contact) {
			if (NumberOfcontacts < 8) {
				contacts[NumberOfcontacts] = contact;
				NumberOfcontacts++;
			}
			else {
				free(contacts[0]);
				for (int i = 0; i < 7; i++) {
					contacts[i] = contacts[i + 1];
				}
				contacts[7] = contact;
			}
		}
		inline void serchContact(int index) {
			if (index < 0) {
				std::cout << "Invalid index" << std::endl;
				return;
			} else if (index >= NumberOfcontacts) {
				std::cout << "Index out of range" << std::endl;
				return;
			}
			std::cout << "First Name: " << contacts[index]->firstName << std::endl;
			std::cout << "Last Name: " << contacts[index]->lastName << std::endl;
			std::cout << "Nickname: " << contacts[index]->nickname << std::endl;
			std::cout << "Phone Number: " << contacts[index]->phoneNumber << std::endl;
			std::cout << "Darkest Secret: " << contacts[index]->darkestSecret << std::endl;
		}
};

#endif
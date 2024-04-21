#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <string>
# include <iostream>
# include "Contact.hpp"

class PhoneBook {
	private:
		Contact	*contacts[8];
		int		NumberOfcontacts;
	
	public:
		inline void addContact(Contact *contact) {
			if (NumberOfcontacts < 8) {
				contacts[NumberOfcontacts] = contact;
				NumberOfcontacts++;
			}
			else {
				delete contacts[0];
				for (int i = 0; i < 7; i++) {
					contacts[i] = contacts[i + 1];
				}
				contacts[7] = contact;
			}
		}
		inline Contact *getContact(int index) {
			if (index < 0 || index >= NumberOfcontacts) {
				return NULL;
			} else {
				return contacts[index];
			}
		}
};

#endif
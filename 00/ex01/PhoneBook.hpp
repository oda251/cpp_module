#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <string>
# include <iostream>
# include "Contact.hpp"
# include "utils.hpp"

class PhoneBook {
	private:
		int					_NumberOfcontacts;
		static const int	_maxContacts = 8;
		Contact				_contacts[8];

	public:
		PhoneBook();
		~PhoneBook();
		int		getNumberOfcontacts();
		void	addContact(Contact contact);
		Contact	*getContact(int index);
		void	searchContact();
		void	inputContact();
};

#endif
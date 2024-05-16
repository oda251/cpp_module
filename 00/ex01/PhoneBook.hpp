/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:31:19 by yoda              #+#    #+#             */
/*   Updated: 2024/05/16 18:37:14 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
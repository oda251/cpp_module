/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:31:19 by yoda              #+#    #+#             */
/*   Updated: 2024/05/16 14:28:06 by yoda             ###   ########.fr       */
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
		Contact	*_contacts[8];
		int		_NumberOfcontacts;
		void	_addContact(Contact *contact);
		Contact	*_getContact(int index);
	
	public:
		PhoneBook();
		~PhoneBook();
		void	searchContact();
		void	addContact();

};

#endif
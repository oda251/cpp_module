/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:31:19 by yoda              #+#    #+#             */
/*   Updated: 2024/04/25 17:45:07 by yoda             ###   ########.fr       */
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
		Contact	*contacts[8];
		int		NumberOfcontacts;
		inline	void _addContact(Contact *contact) {
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
		inline Contact *_getContact(int index) {
			if (index < 0 || index >= NumberOfcontacts) {
				return NULL;
			} else {
				return contacts[index];
			}
		}
	
	public:
		void	searchContact();
		void	addContact();

};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:31:06 by yoda              #+#    #+#             */
/*   Updated: 2024/05/16 18:44:12 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>
# include <iostream>
# include <sstream>
# include "utils.hpp"

class Contact {
	private:
		int			_index;
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
	public:
		Contact();
		~Contact();
		void	setIndex(int index);
		bool	setFirstName(std::string firstName);
		bool	setLastName(std::string lastName);
		bool	setNickname(std::string nickname);
		bool	setPhoneNumber(std::string phoneNumber);
		bool	setDarkestSecret(std::string);
		int		getIndex() const;
		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickname() const;
		std::string	getPhoneNumber() const;
		std::string	getDarkestSecret() const;
		void	displayTrunced() const;
		void	display() const;

		Contact &operator=(const Contact &rhs);
};

void	displayContactHeader();

#endif
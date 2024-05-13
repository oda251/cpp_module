/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:31:06 by yoda              #+#    #+#             */
/*   Updated: 2024/05/14 04:38:00 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>
# include <iostream>
# include <sstream>
# include "utils.hpp"

class Contact {
	public:
		Contact() {};
		~Contact() {};
		int			index;
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;
		static inline void	displayHeader() {
			std::cout << truncate("index") << "|";
			std::cout << truncate("First name") << "|";
			std::cout << truncate("Last name") << "|";
			std::cout << truncate("Nickname") << std::endl;
		}
		inline void		displayTrunced() {
			std::ostringstream oss;
			oss << index;
			std::cout << truncate(oss.str()) << "|";
			std::cout << truncate(firstName) << "|";
			std::cout << truncate(lastName) << "|";
			std::cout << truncate(nickname) << std::endl;
		}
		inline void		display() {
			std::cout << "First name: " << firstName << std::endl;
			std::cout << "Last name: " << lastName << std::endl;
			std::cout << "Nickname: " << nickname << std::endl;
			std::cout << "Phone number: " << phoneNumber << std::endl;
			std::cout << "Darkest secret: " << darkestSecret << std::endl;
		}
};

#endif
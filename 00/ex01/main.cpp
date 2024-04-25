/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:31:09 by yoda              #+#    #+#             */
/*   Updated: 2024/04/25 17:46:03 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main() {
	std::string input;
	PhoneBook phoneBook;

	while (1)
	{
		std::cout << "Enter a command: ";
		std::cin >> input;
		if (input == "ADD") {
			phoneBook.addContact();
		} else if (input == "SEARCH") {
			phoneBook.searchContact();
		} else if (input == "EXIT") {
			std::cout << "EXIT" << std::endl;
			break;
		} else {
			std::cout << "Invalid command" << std::endl;
		}
	}
	return (0);
}

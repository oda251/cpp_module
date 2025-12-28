/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:49:48 by yoda              #+#    #+#             */
/*   Updated: 2024/05/14 04:07:48 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cstdlib>
#include "Harl.hpp"

int main(int argc, char **argv) {
	Harl harl;
	const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	if (argc != 2)
	{
		std::cerr << "Error: invalid arguments\n";
		std::cerr << "usage: ./harl level" << std::endl;
		return EXIT_FAILURE;
	}
	int level = DEBUG;
	std::string arg = argv[1];
	while (level < INVALID && levels[level] != arg)
		level++;
	switch (level) {
		case DEBUG:
			while (level < INVALID)
				harl.complain(levels[level++]);
			break;
		case INFO:
			while (level < INVALID)
				harl.complain(levels[level++]);
			break;
		case WARNING:
			while (level < INVALID)
				harl.complain(levels[level++]);
			break;
		case ERROR:
			while (level < INVALID)
				harl.complain(levels[level++]);
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return EXIT_SUCCESS;
}

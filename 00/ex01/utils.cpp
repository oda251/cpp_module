#include "utils.hpp"

bool	is_valid_phonenum_char(char c) {
	return std::isdigit(c) || c == '-' || c == '+' || c == '(' || c == ')';
}

bool	is_valid_phonenumber(std::string phonenumber) {
	for (size_t i = 0; i < phonenumber.length(); i++) {
		if (!is_valid_phonenum_char(phonenumber[i])) {
			return false;
		}
	}
	return true;
}

bool	is_alnum(std::string str) {
	for (size_t i = 0; i < str.length(); i++) {
		if (!std::isalnum(str[i])) {
			return false;
		}
	}
	return true;
}

std::string	truncate(std::string str) {
	if (str.length() > 10) {
		str.resize(9);
		str.append(".");
	} else if (str.length() < 10) {
		str.insert(0, 10 - str.length(), ' ');
	}
	return str;
}

void reset_cin(void) {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void	safe_cin(std::string &str) {
	while (true) {
		std::getline(std::cin, str);
		if (std::cin.eof()) {
			std::cout << "EXIT" << std::endl;
			exit(EXIT_FAILURE);
		} else if (std::cin.bad()) {
			std::cout << "cin.bad" << std::endl;
			exit(EXIT_FAILURE);
		} else if (std::cin.fail()) {
			std::cout << "Invalid input" << std::endl;
			reset_cin();
		} else {
			break;
		}
	}
}

void	safe_cin_int(int &num) {
	while (true) {
		std::cin >> num;
		if (std::cin.eof()) {
			std::cout << "EXIT" << std::endl;
			exit(EXIT_FAILURE);
		} else if (std::cin.bad()) {
			std::cout << "cin.bad" << std::endl;
			exit(EXIT_FAILURE);
		} else if (std::cin.fail()) {
			std::cout << "Invalid input" << std::endl;
			reset_cin();
		} else {
			reset_cin();
			break;
		}
	}
}

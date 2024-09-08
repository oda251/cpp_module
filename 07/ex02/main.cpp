#include <iostream>
#include <string>
#include "Array.hpp"

int main() {
	Array<int> arr;
	try {
		std::cout << arr[0] << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	Array<char> str(10);
	try {
		std::string src = "hello";
		for (size_t i=0; src[i]; i++) {
			str[i] = src[i];
		}
		str[src.size()] = '\0';

		for (size_t i=0; i<src.size(); i++) {
			std::cout << str[i];
		}
		std::cout << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}

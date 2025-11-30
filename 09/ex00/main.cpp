#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return EXIT_FAILURE;
	}
	std::ifstream file(argv[1]);
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return EXIT_FAILURE;
	}
	BitcoinExchange obj;
	try {
		obj.exchange(file);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
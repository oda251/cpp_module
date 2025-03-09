#include <iostream>
#include "SchalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <value>" << std::endl;
		return 1;
	}
	SchalarConverter::convert(argv[1]);
	return 0;
}

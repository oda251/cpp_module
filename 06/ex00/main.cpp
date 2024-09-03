#include <iostream>
#include <string>
#include <cstdlib>
#include "SchalarConverter.hpp"

int main(void) {
	SchalarConverter::convert("0");
	SchalarConverter::convert("42.0");
	SchalarConverter::convert("42.42f");
	SchalarConverter::convert("42.42");
	SchalarConverter::convert("nan");
	SchalarConverter::convert("-inf");
	SchalarConverter::convert("+inf");
	SchalarConverter::convert("-inff");
	SchalarConverter::convert("+inff");
	return 0;
}

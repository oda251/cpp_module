#include <iostream>
#include "SchalarConverter.hpp"

int main(void) {
	std::cout << "--- 0 ---" << std::endl;
	SchalarConverter::convert("0");
	std::cout << "--- 42 ---" << std::endl;
	SchalarConverter::convert("42");
	std::cout << "--- -42 ---" << std::endl;
	SchalarConverter::convert("-42");
	std::cout << "--- 42.42f ---" << std::endl;
	SchalarConverter::convert("42.42f");
	std::cout << "--- 42.42 ---" << std::endl;
	SchalarConverter::convert("42.42");
	std::cout << "--- nan ---" << std::endl;
	SchalarConverter::convert("nan");
	std::cout << "--- -inf ---" << std::endl;
	SchalarConverter::convert("-inf");
	std::cout << "--- +inf ---" << std::endl;
	SchalarConverter::convert("+inf");
	std::cout << "--- -inff ---" << std::endl;
	SchalarConverter::convert("-inff");
	std::cout << "--- +inff ---" << std::endl;
	SchalarConverter::convert("+inff");
	return 0;
}

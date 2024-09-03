#include "SchalarConverter.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

SchalarConverter::SchalarConverter(void) {}
SchalarConverter::SchalarConverter(SchalarConverter const &other) { (void)other; }
SchalarConverter &SchalarConverter::operator=(SchalarConverter const &other) { (void)other; return *this; }
SchalarConverter::~SchalarConverter(void) {}

e_type detect_type(std::string const &input) {
  if (input.length() == 1 && !std::isdigit(input[0])) {
    return CHAR;
  }
  if (input == "nan" || input == "-inf" || input == "+inf") {
    return DOUBLE;
  }
  if (input == "-inff" || input == "+inff") {
    return FLOAT;
  }
  size_t dot_count = 0;
  for (int i = 0; i < input.length() - 1; i++) {
    if (input[i] == '.') {
      if (dot_count++ > 1) {
        return IMPOSSIBLE;
      }
    } else {
      if (!std::isdigit(input[i])) {
        return IMPOSSIBLE;
      }
    }
  }
  if (input[input.length() - 1] == 'f') {
    return FLOAT;
  } else if (!std::isdigit(input[input.length() - 1])) {
    return IMPOSSIBLE;
  }
  if (dot_count == 1) {
    return DOUBLE;
  }
  return INT;
}

void SchalarConverter::convert(std::string const &input) {
  e_type type = detect_type(input);
  switch (type) {
    case (CHAR) : {
      char c = input[0];
      if (c < 32 || 126 < c)
        std::cout << "char: non printable\n";
      else
        std::cout << "char: " << c << '\n';
      std::cout << "int: " << static_cast<int>(c) << "\n";
    }
  }
  if (input == "nan") {
    std::cout << "char: impossible" << '\n';
    std::cout << "int: impossible" << '\n';
    std::cout << "float: impossible" << '\n';
    std::cout << "double: nan" << std::endl;
    return ;
  }
  if (input == "-inf" || input == "-inff") {
    std::cout << "char: impossible" << '\n';
    std::cout << "int: impossible" << '\n';
    std::cout << "float: -inff" << '\n';
    std::cout << "double: -inf" << std::endl;
    return ;
  }
  if (input == "+inf" || input == "+inff") {
    std::cout << "char: impossible" << '\n';
    std::cout << "int: impossible" << '\n';
    std::cout << "float: inff" << '\n';
    std::cout << "double: inf" << std::endl;
    return ;
  }
  try {
    int i = std::atoi(input.c_str());
    if (i < 32 || i > 126) {
      std::cout << "char: Non displayable" << '\n';
    } else {
      char c = static_cast<char>(i);
      std::cout << "char: '" << c << "'" << '\n';
    }
    std::cout << "int: " << i << '\n';
  } catch (std::exception &e) {
    std::cout << "char: impossible" << '\n';
    std::cout << "int: impossible" << '\n';
  }
  try {
    float f = std::atof(input.c_str());
    std::cout << "float: " << f;
    if (f == static_cast<int>(f))
      std::cout << ".0";
    std::cout << 'f' << '\n';
  } catch (std::exception &e) {
    std::cout << "float: impossible" << '\n';
  }
  try {
    double d = std::atof(input.c_str());
    std::cout << "double: " << d;
    if (d == static_cast<int>(d)) {
      std::cout << ".0";
    }
    std::cout << '\n';
  } catch (std::exception &e) {
    std::cout << "double: impossible" << '\n';
  }
  std::cout << std::flush;
}

#pragma once
#include <string>

class SchalarConverter {
private:
  SchalarConverter(void);
  SchalarConverter(SchalarConverter const &other);
  SchalarConverter &operator=(SchalarConverter const &other);
  ~SchalarConverter(void);
public:
  static void convert(std::string const &input);
};

enum e_type {
  CHAR,
  INT,
  FLOAT,
  DOUBLE,
  IMPOSSIBLE
};

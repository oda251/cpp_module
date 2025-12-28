#include "SchalarConverter.hpp"
#include <string>
#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <cfloat>
#include <sstream>

SchalarConverter::SchalarConverter(void) {}
SchalarConverter::SchalarConverter(SchalarConverter const &other) { (void)other; }
SchalarConverter &SchalarConverter::operator=(SchalarConverter const &other) { (void)other; return *this; }
SchalarConverter::~SchalarConverter(void) {}

e_type detect_type(std::string const &input) {
  if (input.length() == 1) {
    if (std::isdigit(input[0]))
      return INT;
    return CHAR;
  }
  if (input == "nan" || input == "-inf" || input == "+inf") {
    return DOUBLE;
  }
  if (input == "-inff" || input == "+inff") {
    return FLOAT;
  }
  size_t dot_count = 0;
  if (input[0] == '-' || input[0] == '+') {
    if (!std::isdigit(input[1])) {
      return IMPOSSIBLE;
    }
  } else if (!std::isdigit(input[0])) {
    return IMPOSSIBLE;
  }
  for (size_t i = 1; i < input.length() - 1; i++) {
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

static void record(std::ostringstream& result, char c) {
  if (c < 32 || 126 < c)
    result << "non displayable";
  else
    result << "'" << c << "'";
}
static void record(std::ostringstream& result, int i) {
  result << i;
}
static void record(std::ostringstream& result, float f) {
  result << f << "f";
}
static void record(std::ostringstream& result, double d) {
  result << d;
  if (d == static_cast<int>(d)) {
    result << ".0";
  }
}
static void record(std::ostringstream& result, std::string const &s) {
  result << s;
}

void SchalarConverter::convert(std::string const &input) {
  e_type type = detect_type(input);
  std::ostringstream result[4];
  switch (type) {
    case (CHAR) : {
      char c = input[0];
      record(result[CHAR], c);
      record(result[INT], static_cast<int>(c));
      record(result[FLOAT], static_cast<float>(c));
      record(result[DOUBLE], static_cast<double>(c));
      break;
    }
    case (INT) : {
      long tmp = strtol(input.c_str(), NULL, 10);
      if (errno == ERANGE || tmp < INT_MIN || INT_MAX < tmp) {
        for (int i = 0; i < 4; i++)
          record(result[i], "impossible");
        break;
      }
      int i = static_cast<int>(tmp);
      record(result[INT], i);
      if (i < CHAR_MIN || CHAR_MAX < i)
        record(result[CHAR], "impossible");
      else
        record(result[CHAR], static_cast<char>(i));
      record(result[FLOAT], static_cast<float>(i));
      record(result[DOUBLE], static_cast<double>(i));
      break;
    }
    case (FLOAT) : {
      if (input == "-inff" || input == "+inff") {
        record(result[CHAR], "impossible");
        record(result[INT], "impossible");
        record(result[FLOAT], input);
        record(result[DOUBLE], input[0] == '-' ? "-inf" : "+inf");
        break ;
      }
      char* end;
      float f = strtof(input.c_str(), &end);
      if (errno == ERANGE || *end != '\0') {
        for (int i = 0; i < 4; i++)
          record(result[i], "impossible");
        break ;
      }
      record(result[FLOAT], f);
      record(result[DOUBLE], static_cast<double>(f));
      int i = static_cast<int>(f);
      record(result[INT], i);
      if (i < CHAR_MIN || CHAR_MAX < i)
        record(result[CHAR], "impossible");
      else
        record(result[CHAR], static_cast<char>(i));
      break;
    }
    case (DOUBLE) : {
      if (input == "nan") {
        for (int i = 0; i < 3; i++)
          record(result[i], "impossible");
        record(result[DOUBLE], "nan");
        break ;
      } else if (input == "-inf" || input == "+inf") {
        record(result[CHAR], "impossible");
        record(result[INT], "impossible");
        record(result[FLOAT], input + 'f');
        record(result[DOUBLE], input);
        break ;
      }
      char* end;
      double d = strtod(input.c_str(), &end);
      if (errno == ERANGE || *end != '\0') {
        for (int i = 0; i < 4; i++)
          record(result[i], "impossible");
        break ;
      }
      record(result[DOUBLE], d);
      if (d < FLT_MIN || FLT_MAX < d)
        record(result[FLOAT], "impossible");
      else
        record(result[FLOAT], static_cast<float>(d));
      if (d < INT_MIN || INT_MAX < d)
        record(result[INT], "impossible");
      else
        record(result[INT], static_cast<int>(d));
      if (d < CHAR_MIN || CHAR_MAX < d)
        record(result[CHAR], "impossible");
      else
        record(result[CHAR], static_cast<char>(d));
      break;
    }
    default: {
      for (int i = 0; i < 4; i++)
        record(result[i], "impossible");
      break;
    }
  }
  std::cout << "char: " << result[CHAR].str() << '\n';
  std::cout << "int: " << result[INT].str() << '\n';
  std::cout << "float: " << result[FLOAT].str() << '\n';
  std::cout << "double: " << result[DOUBLE].str() << std::endl;
}

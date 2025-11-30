#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) { _loadData(); }
BitcoinExchange::BitcoinExchange(BitcoinExchange const& src) { *this = src; }
BitcoinExchange::~BitcoinExchange(void) {}
BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& rhs) {
  (void)rhs;
  return *this;
}

void BitcoinExchange::_loadData(void) {
  std::ifstream file(DATABASE);
  if (!file.is_open()) {
    throw std::runtime_error(
        std::string("Error: could not open database file: ") + DATABASE);
  }
  std::string line;
  std::getline(file, line);
  while (std::getline(file, line)) {
    Data data;
    if (sscanf(line.c_str(), "%d-%d-%d,%lf", &data.year, &data.month, &data.day,
               &data.rate) != 4) {
      throw std::runtime_error(std::string("Error: could not parse line: ") +
                               line);
    }
    _data.insert(data);
  }
}

bool is_digit(char c) { return c >= '0' && c <= '9'; }

Data parseData(const std::string& line) {
  Data data;
  Data invalid;
  invalid.year = -1;
  data.year = 0;
  data.month = 0;
  data.day = 0;
  data.rate = 0;
  size_t i = 0;
  for (; i < line.size() && is_digit(line[i]); i++) {
    data.year = data.year * 10 + line[i] - '0';
    if (data.year > 9999) {
      return invalid;
    }
  }
  if (data.year == 0 || line[i] != '-') {
    return invalid;
  }
  ++i;
  for (; i < line.size() && is_digit(line[i]); i++) {
    data.month = data.month * 10 + line[i] - '0';
    if (data.month > 12) {
      return invalid;
    }
  }
  if (data.month == 0 || line[i] != '-') {
    return invalid;
  }
  ++i;
  for (; i < line.size() && is_digit(line[i]); i++) {
    data.day = data.day * 10 + line[i] - '0';
    if (data.month == 2) {
      if (data.year % 4 == 0) {
        if (data.year % 100 == 0 && data.year % 400 != 0) {
          if (data.day > 28) {
            return invalid;
          }
        } else if (data.day > 29) {
          return invalid;
        }
      } else {
        if (data.day > 28) {
          return invalid;
        }
      }
    }
    if ((data.month == 4 || data.month == 6 || data.month == 9 ||
         data.month == 11) &&
        data.day > 30) {
      return invalid;
    }
    if (data.day > 31) {
      return invalid;
    }
  }
  if (data.day == 0 || line[i] != ' ' || line[i + 1] != '|' ||
      line[i + 2] != ' ') {
    return invalid;
  }
  i += 3;
  if (line[i] == '-') {
    data.rate = -1;
    return data;
  }
  for (; i < line.size() && is_digit(line[i]); i++) {
    data.rate = data.rate * 10 + line[i] - '0';
    if (data.rate > 9999) {
      data.rate = 10000;
      return data;
    }
  }
  if (line[i] == '.') {
    i++;
    double decimal = 0.1;
    for (; i < line.size() && is_digit(line[i]) && decimal > 0; i++) {
      double delta = (line[i] - '0') * decimal;
      data.rate += delta;
      decimal /= 10;
    }
  }
  return data;
}

void BitcoinExchange::calculate(const Data& data) {
  std::cout << data.year << "-" << data.month << "-" << data.day << " => "
            << data.rate << " = ";
  double rate = 0;
  for (size_t i = 0; i < _data.size(); i++) {
    if (_data[i].year > data.year) {
      break;
    }
    if (_data[i].year == data.year && _data[i].month > data.month) {
      break;
    }
    if (_data[i].year == data.year && _data[i].month == data.month &&
        _data[i].day > data.day) {
      break;
    }
    rate = _data[i].rate;
  }
  std::cout << data.rate * rate << std::endl;
}

void BitcoinExchange::exchange(std::ifstream& input) {
  std::string line;
  std::getline(input, line);
  if (line != "date | value") {
    throw std::runtime_error(
        "Error: invalid format. input should start with \"date | value\"");
  }
  while (std::getline(input, line)) {
    Data data = parseData(line);
    if (data.year == -1) {
      std::cout << BAD_INPUT << line << std::endl;
    } else if (data.rate < 0) {
      std::cout << NOT_POSITIVE << std::endl;
    } else if (data.rate > 9999) {
      std::cout << TOO_LARGE << std::endl;
    } else {
      calculate(data);
    }
  }
}

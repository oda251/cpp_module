#include "BitcoinExchange.hpp"

bool Data::operator<(const Data& other) const {
  if (year != other.year) {
    return year < other.year;
  }
  if (month != other.month) {
    return month < other.month;
  }
  return day < other.day;
}

BitcoinExchange::BitcoinExchange(void) { _loadData(); }
BitcoinExchange::BitcoinExchange(BitcoinExchange const& src) { *this = src; }
BitcoinExchange::~BitcoinExchange(void) {}
BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& rhs) {
  (void)rhs;
  return *this;
}

void BitcoinExchange::_loadData(void) {
  std::ifstream file;
  try {
    file.open(DATABASE);
  } catch (...) {
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
    if (data.rate > 1000) {
      data.rate = 1000;
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
  std::set<Data>::iterator it = _data.upper_bound(data);

  if (it == _data.begin()) {
    std::cout << "Error: date too old." << std::endl;
    return;
  }
  --it;

  std::cout << data.year << "-" << (data.month < 10 ? "0" : "") << data.month
            << "-" << (data.day < 10 ? "0" : "") << data.day << " => "
            << data.rate << " = " << data.rate * it->rate << std::endl;
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
    } else if (data.rate >= 1000) {
      std::cout << TOO_LARGE << std::endl;
    } else {
      calculate(data);
    }
  }
}

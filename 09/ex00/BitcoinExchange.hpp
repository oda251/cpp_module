#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <limits.h>

#define DATABASE "data.csv"
#define NOT_POSITIVE "Error: not a positive number."
#define BAD_INPUT "Error: bad input => "
#define TOO_LARGE "Error: too large number."

struct Data {
  int year;
  int month;
  int day;
  double rate;
};

class BitcoinExchange {
 private:
  BitcoinExchange(BitcoinExchange const& src);
  BitcoinExchange& operator=(BitcoinExchange const& rhs);
  void _loadData(void);
  std::vector<Data> _data;
  void calculate(const Data& data);
 public:
  BitcoinExchange(void);
  ~BitcoinExchange(void);
  void exchange(std::ifstream& input);
};

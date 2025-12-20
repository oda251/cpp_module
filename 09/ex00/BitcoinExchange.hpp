#pragma once
#include <limits.h>

#include <fstream>
#include <iostream>
#include <set>
#include <string>

#define DATABASE "data.csv"
#define NOT_POSITIVE "Error: not a positive number."
#define BAD_INPUT "Error: bad input => "
#define TOO_LARGE "Error: too large number."

struct Data {
  int year;
  int month;
  int day;
  double rate;

  bool operator<(const Data& other) const;
};

class BitcoinExchange {
 private:
  BitcoinExchange(BitcoinExchange const& src);
  BitcoinExchange& operator=(BitcoinExchange const& rhs);
  void _loadData(void);
  std::set<Data> _data;
  void calculate(const Data& data);

 public:
  BitcoinExchange(void);
  ~BitcoinExchange(void);
  void exchange(std::ifstream& input);
};

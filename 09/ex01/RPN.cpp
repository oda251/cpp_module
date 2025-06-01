#include "RPN.hpp"

long long stoi(const std::string& s) {
  if (s.empty()) {
    return LLONG_MIN;
  }
  size_t i = 0;
  long long n = 0;
  int sign = 1;
  if (s[i] == '-') {
    i++;
    sign = -1;
  }
  for (; i < s.size(); i++) {
    if (!std::isdigit(s[i])) {
      return LLONG_MIN;
    }
    n = n * 10 + s[i] - '0';
    if (n > INT_MAX) {
      return LLONG_MIN;
    }
  }
  return n * sign;
}

int rpn(std::string const& expr) {
  std::stack<int> stack;
  size_t i = 0;
  while (i < expr.size()) {
    std::string token;
    while (i < expr.size() && expr[i] == ' ') {
      i++;
    }
    while (i < expr.size() && expr[i] != ' ') {
      token += expr[i];
      i++;
    }
    if (token == "+" || token == "-" || token == "*" || token == "/") {
      if (stack.size() < 2) {
        return 0;
      }
      int a = stack.top();
      stack.pop();
      int b = stack.top();
      stack.pop();
      switch (token[0]) {
        case '+':
          stack.push(b + a);
          break;
        case '-':
          stack.push(b - a);
          break;
        case '*':
          stack.push(b * a);
          break;
        case '/':
          stack.push(b / a);
          break;
      }
    } else {
      long long n = stoi(token);
      if (n == LLONG_MIN) {
        throw std::runtime_error("Error");
      }
      stack.push(n);
    }
  }
  if (stack.size() != 1) {
    throw std::runtime_error("Error");
  }
  return stack.top();
}
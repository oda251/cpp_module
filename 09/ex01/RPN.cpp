#include "RPN.hpp"

long long ft_stoi(const std::string& s) {
  std::stringstream ss(s);
  ss.clear();
  ss.str(s);
  long long n;
  ss >> n;
  if (ss.fail() || !ss.eof()) {
    throw std::runtime_error("Error");
  }
  if (n < 0 || n >= 10) {
    throw std::runtime_error("Error");
  }
  return n;
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
        throw std::runtime_error("Error");
      }
      int a = stack.top();
      stack.pop();
      int b = stack.top();
      stack.pop();
      int result;
      switch (token[0]) {
        case '+':
          if (__builtin_add_overflow(a, b, &result)) {
            throw std::runtime_error("Error");
          }
          stack.push(result);
          break;
        case '-':
          if (__builtin_sub_overflow(b, a, &result)) {
            throw std::runtime_error("Error");
          }
          stack.push(result);
          break;
        case '*':
          if (__builtin_mul_overflow(a, b, &result)) {
            throw std::runtime_error("Error");
          }
          stack.push(result);
          break;
        case '/':
          if (a == 0) {
            throw std::runtime_error("Error");
          }
          if ((a == INT_MIN && b == -1) || (a == -1 && b == INT_MIN)) {
            throw std::runtime_error("Error");
          }
          stack.push(b / a);
          break;
      }
    } else {
      long long n = ft_stoi(token);
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
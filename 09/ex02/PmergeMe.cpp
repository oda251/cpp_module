#include "PmergeMe.hpp"

int Jacobsthal(int n) {
  static std::vector<int> memo = {0, 1};
  if (n < memo.size()) {
    return memo[n];
  }
  while (memo.size() <= n) {
    int next_value = memo[memo.size() - 1] + 2 * memo[memo.size() - 2];
    memo.push_back(next_value);
  }
  return memo[n];
}

template <typename Container>
void solve_first(Container& input, Container& output) {
  output = input;
  std::sort(output.begin(), output.end());
}

void PmergeMe::interpret_args(const int argc, char** argv,
                              PmergeMe::ContainerType type) {
  if (argc < 2) {
    throw std::invalid_argument("No arguments provided.");
  } else if (argc > MAX_SIZE + 1) {
    throw std::invalid_argument("Too many arguments provided. Maximum is " +
                                std::to_string(MAX_SIZE));
  }
  for (int i = 1; i < argc; ++i) {
    if (!argv[i] || !*argv[i]) {
      throw std::invalid_argument("Invalid argument: empty string");
    }
    long value = std::atol(argv[i]);
    if (value <= 0 || value > INT_MAX) {
      throw std::invalid_argument("Invalid argument: " + std::string(argv[i]));
    }
    if (type == ContainerType::VECTOR) {
      origin_vector.push_back(value);
    } else if (type == ContainerType::DEQUE) {
      origin_deque.push_back(value);
    }
  }
}

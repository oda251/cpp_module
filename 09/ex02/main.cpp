#include "PmergeMe.hpp"

void interpret_args(int argc, char** argv, int* dest);

int main(int argc, char** argv) {
  std::vector<int> origin_vector;
  std::deque<int> origin_deque;
  try {
    interpret_args<std::vector<int>>(argc, argv, origin_vector);
    interpret_args<std::deque<int>>(argc, argv, origin_deque);
  } catch (const std::invalid_argument& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return EXIT_FAILURE;
  } catch (const std::exception& e) {
    std::cerr << "Unexpected error: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

template <typename Container>
void interpret_args(const int argc, char const* const* argv,
                    Container& dest) {
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
    dest.push_back(value);
  }
}

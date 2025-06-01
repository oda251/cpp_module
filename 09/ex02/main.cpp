#include "PmergeMe.hpp"

int conv_str_to_int(const std::string& str);

int main(int argc, char** argv) {
  // validation
  if (argc < 2) {
    std::cerr << "Error: No arguments provided." << std::endl;
    return EXIT_FAILURE;
  }
  // input
  std::vector<int> vec_origin;
  std::deque<int> deq_origin;
  for (int i = 1; i < argc; i++) {
    int num = conv_str_to_int(argv[i]);
    if (num <= 0) {
      std::cerr << "Error: Invalid number or out of range." << std::endl;
      return EXIT_FAILURE;
    }
    vec_origin.push_back(num);
    deq_origin.push_back(num);
  }
  // ouput the original vector
  std::cout << "Before: ";
  for (size_t i = 0; i < vec_origin.size(); i++) {
    std::cout << vec_origin[i];
    if (i != vec_origin.size() - 1) {
      std::cout << " ";
    }
  }
  std::cout << std::endl;

  // get the time
  time_t start_vec = time(NULL);
  // sort the vector

  // output the time
  time_t end_vec = time(NULL);
  // get the time
  time_t start_deq = time(NULL);
  // sort the deque
  // output the time
  time_t end_deq = time(NULL);
  return EXIT_SUCCESS;
}

// return 0 if str is not a number or out of range
int conv_str_to_int(const std::string& str) {
  int num = 0;
  for (size_t i = 0; i < str.size(); i++) {
    if (!std::isdigit(str[i])) {
      return 0;
    }
    if (num > INT_MAX / 10) {
      return 0;
    }
    num = num * 10 + str[i] - '0';
  }
  return num;
}
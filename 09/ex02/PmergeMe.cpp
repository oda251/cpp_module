#include "PmergeMe.hpp"

#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <vector>

#define MICROSECONDS_PER_SECOND 1000000.0

PmergeMe::PmergeMe(int argc, char** argv) : time_vector(0), time_deque(0) {
  if (argc < 2) {
    throw std::invalid_argument("No arguments provided.");
  }

  std::stringstream ss;
  std::vector<int> check_dup;

  for (int i = 1; i < argc; ++i) {
    if (!argv[i] || !*argv[i]) {
      throw std::invalid_argument("Invalid argument: empty string");
    }
    ss.clear();
    ss.str(argv[i]);
    int value;
    ss >> value;
    if (value < 0 || ss.fail() || !ss.eof()) {
      std::ostringstream oss;
      oss << "Invalid argument: " << argv[i];
      throw std::invalid_argument(oss.str());
    }
    if (std::find(check_dup.begin(), check_dup.end(), value) !=
        check_dup.end()) {
      std::ostringstream oss;
      oss << "Duplicate argument: " << value;
      throw std::invalid_argument(oss.str());
    }
    check_dup.push_back(value);

    origin_vector.push_back(static_cast<int>(value));
    origin_deque.push_back(static_cast<int>(value));
  }
}
PmergeMe::PmergeMe(const PmergeMe& other)
    : origin_vector(other.origin_vector),
      origin_deque(other.origin_deque),
      sorted_vector(other.sorted_vector),
      sorted_deque(other.sorted_deque),
      time_vector(other.time_vector),
      time_deque(other.time_deque) {}
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
  if (this != &other) {
    origin_vector = other.origin_vector;
    origin_deque = other.origin_deque;
    sorted_vector = other.sorted_vector;
    sorted_deque = other.sorted_deque;
    time_vector = other.time_vector;
    time_deque = other.time_deque;
  }
  return *this;
}
PmergeMe::~PmergeMe(void) {}

unsigned long long PmergeMe::getJacobsthal(unsigned long long n) {
  static std::vector<unsigned long> memo;
  if (memo.empty()) {
    memo.push_back(0);
    memo.push_back(1);
  }
  if (memo.size() > n) return memo[n];
  return memo[n] = getJacobsthal(n - 1) + 2 * getJacobsthal(n - 2);
}

template <typename Container>
void PmergeMe::mergeInsertionSort(Container& arr) {
  size_t n = arr.size();
  if (n <= 1) return;

  bool has_straggler = (n % 2 != 0);
  int straggler = 0;
  if (has_straggler) {
    straggler = arr.back();
    arr.pop_back();
  }

  Container larger_elements;
  std::map<int, int> pairs_map;

  size_t pair_count = arr.size() / 2;
  for (size_t i = 0; i < pair_count; ++i) {
    int a = arr[2 * i];
    int b = arr[2 * i + 1];

    if (a < b) {
      std::swap(a, b);
    }
    pairs_map[a] = b;
    larger_elements.push_back(a);
  }

  mergeInsertionSort(larger_elements);
  arr = larger_elements;

  if (!arr.empty()) {
    int first_partner = pairs_map[arr[0]];
    arr.insert(arr.begin(), first_partner);
  }

  Container main_chain = larger_elements;
  size_t main_chain_size = main_chain.size();

  unsigned long long jacob_idx = 3;
  unsigned long long prev_jacob_idx = 1;

  while (true) {
    unsigned long long curr_st = PmergeMe::getJacobsthal(jacob_idx);
    unsigned long long group_end = curr_st;
    if (group_end > main_chain_size) {
      group_end = main_chain_size;
    }

    for (size_t i = group_end - 1; i >= prev_jacob_idx; --i) {
      if (i >= main_chain.size()) continue;
      int winner = main_chain[i];
      int pending_element = pairs_map[winner];
      int bound_element = winner;

      typename Container::iterator bit = arr.begin();
      while (bit != arr.end() && *bit != bound_element) {
        bit++;
      }

      typename Container::iterator pos =
          std::lower_bound(arr.begin(), bit, pending_element);
      arr.insert(pos, pending_element);
    }

    prev_jacob_idx = group_end;
    jacob_idx++;

    if (prev_jacob_idx >= main_chain_size) break;
  }

  if (has_straggler) {
    typename Container::iterator pos =
        std::lower_bound(arr.begin(), arr.end(), straggler);
    arr.insert(pos, straggler);
  }
}

void PmergeMe::run(void) {
  std::vector<int> copied_vector = origin_vector;

  clock_t start = clock();
  mergeInsertionSort(copied_vector);
  clock_t end = clock();
  time_vector =
      (double)(end - start) / CLOCKS_PER_SEC * MICROSECONDS_PER_SECOND;

  sorted_vector = copied_vector;

  std::deque<int> copied_deque = origin_deque;

  start = clock();
  mergeInsertionSort(copied_deque);
  end = clock();
  time_deque = (double)(end - start) / CLOCKS_PER_SEC * MICROSECONDS_PER_SECOND;

  sorted_deque = copied_deque;
}

void PmergeMe::printResults(void) const {
  std::cout << "Before: ";
  for (size_t i = 0; i < origin_vector.size() && i < 5; ++i) {
    std::cout << origin_vector[i] << " ";
  }
  if (origin_vector.size() > 5) {
    std::cout << "[...]";
  }
  std::cout << std::endl;

  std::cout << "After:  ";
  for (size_t i = 0; i < sorted_vector.size() && i < 5; ++i) {
    std::cout << sorted_vector[i] << " ";
  }
  if (sorted_vector.size() > 5) {
    std::cout << "[...]";
  }
  std::cout << std::endl;

  std::cout << "Time to process a range of " << origin_vector.size()
            << " elements with std::vector : " << time_vector << " us"
            << std::endl;
  std::cout << "Time to process a range of " << origin_deque.size()
            << " elements with std::deque  : " << time_deque << " us"
            << std::endl;
}

template void PmergeMe::mergeInsertionSort<std::vector<int> >(
    std::vector<int>&);
template void PmergeMe::mergeInsertionSort<std::deque<int> >(std::deque<int>&);

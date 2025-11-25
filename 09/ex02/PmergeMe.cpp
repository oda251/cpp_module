#include "PmergeMe.hpp"
#include <cctype>
#define MICROSECONDS_PER_SECOND 1000000.0

PmergeMe::PmergeMe(int argc, char** argv) : time_vector(0), time_deque(0), CNT(0) {
  if (argc < 2) {
    throw std::invalid_argument("No arguments provided.");
  }
  if (argc > MAX_SIZE + 1) {
    std::ostringstream oss;
    oss << "Too many arguments provided. Maximum is " << MAX_SIZE;
    throw std::invalid_argument(oss.str());
  }

  std::stringstream ss;
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
      time_deque(other.time_deque),
      CNT(other.CNT) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
  if (this != &other) {
    origin_vector = other.origin_vector;
    origin_deque = other.origin_deque;
    sorted_vector = other.sorted_vector;
    sorted_deque = other.sorted_deque;
    time_vector = other.time_vector;
    time_deque = other.time_deque;
    CNT = other.CNT;
  }
  return *this;
}

PmergeMe::~PmergeMe(void) {}

int PmergeMe::jacobsthal(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;

  int prev2 = 0;
  int prev1 = 1;
  int current = 0;

  for (int i = 2; i <= n; ++i) {
    current = prev1 + 2 * prev2;
    prev2 = prev1;
    prev1 = current;
  }

  return current;
}

std::vector<int> PmergeMe::generateJacobsthalSequence(int n) {
  std::vector<int> sequence;
  for (int i = 2; jacobsthal(i) < n; ++i) {
    sequence.push_back(jacobsthal(i));
  }
  return sequence;
}

namespace {
int* comparison_counter = NULL;
bool comparison_function(int a, int b) {
  if (comparison_counter) {
    (*comparison_counter)++;
  }
  return a < b;
}
}

template <typename Container>
void PmergeMe::binaryInsert(Container& sorted, int value,
                            typename Container::iterator end) {
  comparison_counter = &this->CNT;
  typename Container::iterator pos =
      std::lower_bound(sorted.begin(), end, value, comparison_function);
  sorted.insert(pos, value);
}

template <typename T>
void sortPairs(T& pairs, int& CNT) {
  if (pairs.size() <= 1) return;

  T left, right;
  for (size_t i = 0; i < pairs.size(); i++) {
    if (i < pairs.size() / 2) {
      left.push_back(pairs[i]);
    } else {
      right.push_back(pairs[i]);
    }
  }

  sortPairs(left, CNT);
  sortPairs(right, CNT);

  size_t i = 0, j = 0, k = 0;
  while (i < left.size() && j < right.size()) {
    CNT++;
    if (left[i].a < right[j].a) {
      pairs[k++] = left[i++];
    } else {
      pairs[k++] = right[j++];
    }
  }
  while (i < left.size()) {
    pairs[k++] = left[i++];
  }
  while (j < right.size()) {
    pairs[k++] = right[j++];
  }
}

template <typename Container, typename T>
void PmergeMe::mergeInsertionSort(Container& arr, T& dummy) {
  (void)dummy;
  size_t n = arr.size();
  if (n <= 1) return;

  T pairs;
  int straggler;
  bool hasStraggler = false;
  if (n % 2 != 0) {
    straggler = arr.back();
    hasStraggler = true;
    arr.pop_back();
  }

  for (size_t i = 0; i < arr.size(); i += 2) {
    CNT++;
    if (arr[i] > arr[i + 1]) {
      pairs.push_back((Node){arr[i], arr[i + 1]});
    } else {
      pairs.push_back((Node){arr[i + 1], arr[i]});
    }
  }

  sortPairs(pairs, this->CNT);

  Container main_chain;
  Container pend_chain;
  for (size_t i = 0; i < pairs.size(); i++) {
    main_chain.push_back(pairs[i].a);
    pend_chain.push_back(pairs[i].b);
  }
  if (!pend_chain.empty()) {
    main_chain.insert(main_chain.begin(), pend_chain.front());
  }

  std::vector<int> jacobsthal_sequence = generateJacobsthalSequence(pend_chain.size() + 1);
  int last_jacob = 1;
  for (size_t i = 0; i < jacobsthal_sequence.size(); i++) {
    int jacob = jacobsthal_sequence[i];
    for (int j = jacob; j > last_jacob; j--) {
      if (j > (int)pend_chain.size()) continue;
      typename Container::iterator end = main_chain.begin();
      std::advance(end, j);
      binaryInsert(main_chain, pend_chain[j - 1], end);
    }
    last_jacob = jacob;
  }
  for (size_t i = last_jacob; i < pend_chain.size(); i++) {
    binaryInsert(main_chain, pend_chain[i], main_chain.end());
  }

  if (hasStraggler) {
    binaryInsert(main_chain, straggler, main_chain.end());
  }
  arr = main_chain;
}

void PmergeMe::run(void) {
  sorted_vector = origin_vector;
  clock_t start = clock();
  std::vector<Node> dummy_vector;
  CNT = 0;
  mergeInsertionSort(sorted_vector, dummy_vector);
  clock_t end = clock();
  time_vector =
      (double)(end - start) / CLOCKS_PER_SEC * MICROSECONDS_PER_SECOND;
  int vector_comparisons = CNT;

  sorted_deque = origin_deque;
  start = clock();
  std::deque<Node> dummy_deque;
  CNT = 0;
  mergeInsertionSort(sorted_deque, dummy_deque);
  end = clock();
  time_deque = (double)(end - start) / CLOCKS_PER_SEC * MICROSECONDS_PER_SECOND;
  int deque_comparisons = CNT;

  // For printing, we'll just show the vector's comparison count,
  // as they should be identical.
  CNT = vector_comparisons;
  if (vector_comparisons != deque_comparisons) {
    std::cerr << "Warning: comparison counts differ between vector and deque." << std::endl;
  }
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
  std::cout << "Comparisons: " << CNT << std::endl;
}

template void PmergeMe::mergeInsertionSort<std::vector<int>, std::vector<PmergeMe::Node> >(
    std::vector<int>&, std::vector<PmergeMe::Node>&);
template void PmergeMe::mergeInsertionSort<std::deque<int>, std::deque<PmergeMe::Node> >(
    std::deque<int>&, std::deque<PmergeMe::Node>&);
template void PmergeMe::binaryInsert<std::vector<int> >(
    std::vector<int>&, int, std::vector<int>::iterator);
template void PmergeMe::binaryInsert<std::deque<int> >(
    std::deque<int>&, int, std::deque<int>::iterator);

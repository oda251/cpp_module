#include "PmergeMe.hpp"
#include <cctype>

#define MICROSECONDS_PER_SECOND 1000000.0

// Constructor
PmergeMe::PmergeMe(int argc, char** argv)
    : time_vector(0), time_deque(0) {
  if (argc < 2) {
    throw std::invalid_argument("No arguments provided.");
  }
  if (argc > MAX_SIZE + 1) {
    std::ostringstream oss;
    oss << "Too many arguments provided. Maximum is " << MAX_SIZE;
    throw std::invalid_argument(oss.str());
  }
  
  // Parse arguments and populate both containers
  for (int i = 1; i < argc; ++i) {
    if (!argv[i] || !*argv[i]) {
      throw std::invalid_argument("Invalid argument: empty string");
    }
    
    // Check if all characters are digits
    for (int j = 0; argv[i][j]; ++j) {
      if (!std::isdigit(argv[i][j])) {
        std::ostringstream oss;
        oss << "Invalid argument: " << argv[i];
        throw std::invalid_argument(oss.str());
      }
    }
    
    long value = std::atol(argv[i]);
    if (value <= 0 || value > INT_MAX) {
      std::ostringstream oss;
      oss << "Invalid argument: " << argv[i];
      throw std::invalid_argument(oss.str());
    }
    
    origin_vector.push_back(static_cast<int>(value));
    origin_deque.push_back(static_cast<int>(value));
  }
}

// Copy constructor
PmergeMe::PmergeMe(const PmergeMe& other)
    : origin_vector(other.origin_vector),
      origin_deque(other.origin_deque),
      sorted_vector(other.sorted_vector),
      sorted_deque(other.sorted_deque),
      time_vector(other.time_vector),
      time_deque(other.time_deque) {}

// Assignment operator
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

// Destructor
PmergeMe::~PmergeMe(void) {}

// Calculate Jacobsthal number
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

// Generate Jacobsthal sequence for insertion order
std::vector<int> PmergeMe::generateJacobsthalSequence(int n) {
  std::vector<int> sequence;
  if (n == 0) return sequence;
  
  int index = 3;
  while (true) {
    int jacob = jacobsthal(index);
    if (jacob >= n) break;
    sequence.push_back(jacob);
    ++index;
  }
  
  return sequence;
}

// Binary insertion to maintain sorted order
template <typename Container>
void PmergeMe::binaryInsert(Container& sorted, int value) {
  typename Container::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), value);
  sorted.insert(pos, value);
}

// Ford-Johnson merge insertion sort implementation
template <typename Container>
void PmergeMe::mergeInsertionSort(Container& arr) {
  size_t n = arr.size();
  
  // Base cases
  if (n <= 1) return;
  
  if (n == 2) {
    if (arr[0] > arr[1]) {
      std::swap(arr[0], arr[1]);
    }
    return;
  }
  
  // Step 1: Create pairs and sort each pair
  // We need to keep track of pairs - store as indices
  std::vector<std::pair<int, int> > pairs;  // (larger_value, smaller_value)
  bool hasStraggler = (n % 2 == 1);
  int straggler = hasStraggler ? arr[n - 1] : 0;
  
  size_t pairCount = n / 2;
  for (size_t i = 0; i < pairCount; ++i) {
    int a = arr[2 * i];
    int b = arr[2 * i + 1];
    if (a > b) {
      pairs.push_back(std::make_pair(a, b));
    } else {
      pairs.push_back(std::make_pair(b, a));
    }
  }
  
  // Step 2: Sort pairs by their larger element using a simple sort
  // We'll use insertion sort to maintain the pairing
  for (size_t i = 1; i < pairs.size(); ++i) {
    std::pair<int, int> key = pairs[i];
    int j = i - 1;
    while (j >= 0 && pairs[j].first > key.first) {
      pairs[j + 1] = pairs[j];
      --j;
    }
    pairs[j + 1] = key;
  }
  
  // Step 3: Create the main chain starting with the first smaller element
  Container mainChain;
  if (!pairs.empty()) {
    mainChain.push_back(pairs[0].second);  // First smaller element
  }
  
  // Add all larger elements to main chain (they're already sorted)
  for (size_t i = 0; i < pairs.size(); ++i) {
    mainChain.push_back(pairs[i].first);
  }
  
  // Step 4: Insert remaining smaller elements using Jacobsthal sequence
  std::vector<int> jacobSequence = generateJacobsthalSequence(pairs.size());
  std::vector<bool> inserted(pairs.size(), false);
  if (!pairs.empty()) {
    inserted[0] = true;  // First element already in chain
  }
  
  // Insert according to Jacobsthal sequence
  for (size_t i = 0; i < jacobSequence.size(); ++i) {
    int pos = jacobSequence[i] - 1;
    if (pos >= 0 && pos < static_cast<int>(pairs.size()) && !inserted[pos]) {
      binaryInsert(mainChain, pairs[pos].second);
      inserted[pos] = true;
    }
    
    // Insert elements between previous and current Jacobsthal number in reverse
    int prevJacob = (i == 0) ? 1 : jacobSequence[i - 1];
    for (int j = jacobSequence[i] - 2; j >= prevJacob; --j) {
      if (j >= 0 && j < static_cast<int>(pairs.size()) && !inserted[j]) {
        binaryInsert(mainChain, pairs[j].second);
        inserted[j] = true;
      }
    }
  }
  
  // Insert any remaining elements
  for (size_t i = 0; i < pairs.size(); ++i) {
    if (!inserted[i]) {
      binaryInsert(mainChain, pairs[i].second);
    }
  }
  
  // Insert straggler if exists
  if (hasStraggler) {
    binaryInsert(mainChain, straggler);
  }
  
  // Copy result back
  arr = mainChain;
}

// Run the sorting algorithm on both containers
void PmergeMe::run(void) {
  // Sort with vector
  sorted_vector = origin_vector;
  clock_t start = clock();
  mergeInsertionSort(sorted_vector);
  clock_t end = clock();
  time_vector = (double)(end - start) / CLOCKS_PER_SEC * MICROSECONDS_PER_SECOND;
  
  // Sort with deque
  sorted_deque = origin_deque;
  start = clock();
  mergeInsertionSort(sorted_deque);
  end = clock();
  time_deque = (double)(end - start) / CLOCKS_PER_SEC * MICROSECONDS_PER_SECOND;
}

// Print results
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
            << " elements with std::vector : " << time_vector << " us" << std::endl;
  std::cout << "Time to process a range of " << origin_deque.size() 
            << " elements with std::deque  : " << time_deque << " us" << std::endl;
}

// Explicit template instantiation
template void PmergeMe::mergeInsertionSort<std::vector<int> >(std::vector<int>&);
template void PmergeMe::mergeInsertionSort<std::deque<int> >(std::deque<int>&);
template void PmergeMe::binaryInsert<std::vector<int> >(std::vector<int>&, int);
template void PmergeMe::binaryInsert<std::deque<int> >(std::deque<int>&, int);

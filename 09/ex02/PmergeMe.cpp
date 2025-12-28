#include "PmergeMe.hpp"

#define MICROSECONDS_PER_SECOND 1000000.0

PmergeMe::PmergeMe(int argc, char** argv) : time_vector(0), time_deque(0) {
  if (argc < 2) {
    throw std::invalid_argument("No arguments provided.");
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
  memo.push_back(getJacobsthal(n - 1) + 2 * getJacobsthal(n - 2));
  return memo[n];
}

template <typename Container>
void PmergeMe::fordJohnsonRecursive(Container& elements) {
  size_t n = elements.size();
  if (n <= 1) return;

  Container winners;
  bool has_straggler = (n % 2 != 0);
  size_t pair_count = n / 2;

  for (size_t i = 0; i < pair_count; ++i) {
    ChainElement* e1 = elements[2 * i];
    ChainElement* e2 = elements[2 * i + 1];

    if (e1->value < e2->value) {
      std::swap(e1, e2);
    }
    // e1 is now the winner, e2 is the loser at this level
    e1->losers.push_back(e2);
    winners.push_back(e1);
  }

  ChainElement* straggler = has_straggler ? elements.back() : NULL;

  // Recursively sort the winners
  fordJohnsonRecursive(winners);

  // winners is now sorted: [w1, w2, w3, ..., wk]
  // Create main_chain. The first loser (b1) is paired with w1.
  // b1 < w1 is guaranteed, and it's always the first element of the sorted list.
  Container main_chain;
  main_chain.push_back(winners[0]->losers.back()); // b1
  winners[0]->losers.pop_back();                   // Remove b1 from history
  for (size_t i = 0; i < winners.size(); ++i) {
    main_chain.push_back(winners[i]);
  }

  // Pending elements (b2, b3, ...) are the top of the history stack of each winner
  // Jacobsthal groups
  unsigned long long jacob_idx = 3;
  size_t last_inserted_idx = 1; // b1 is already at index 0 in winners context

  while (last_inserted_idx < winners.size() || straggler) {
    unsigned long long curr_jacob = getJacobsthal(jacob_idx);
    size_t group_end = (curr_jacob > winners.size()) ? winners.size() : static_cast<size_t>(curr_jacob);

    // Insert group members in reverse order (b_group_end down to b_last+1)
    for (size_t i = group_end; i > last_inserted_idx; --i) {
      ChainElement* pending = winners[i - 1]->losers.back();
      winners[i - 1]->losers.pop_back();

      // Binary search: the upper bound is the position of its winner in main_chain
      typename Container::iterator it_winner =
          std::find(main_chain.begin(), main_chain.end(), winners[i - 1]);
      typename Container::iterator pos =
          std::lower_bound(main_chain.begin(), it_winner, pending, ChainComparator());
      main_chain.insert(pos, pending);
    }

    if (last_inserted_idx == winners.size() && straggler) {
      typename Container::iterator pos =
          std::lower_bound(main_chain.begin(), main_chain.end(), straggler, ChainComparator());
      main_chain.insert(pos, straggler);
      straggler = NULL;
    }

    last_inserted_idx = group_end;
    jacob_idx++;
  }

  elements = main_chain;
}

template <typename RawContainer, typename ElementContainer>
void PmergeMe::sortContainer(RawContainer& raw, RawContainer& sorted) {
  if (raw.empty()) return;

  // 1. Create a pool of objects to manage memory safely
  ElementContainer pool;
  for (size_t i = 0; i < raw.size(); ++i) {
    pool.push_back(ChainElement(raw[i]));
  }

  // 2. Create a container of pointers level 0
  typename std::vector<ChainElement*> ptrs;
  for (size_t i = 0; i < pool.size(); ++i) {
    ptrs.push_back(&pool[i]);
  }

  // 3. Run recursive Ford-Johnson
  fordJohnsonRecursive(ptrs);

  // 4. Extract sorted values
  sorted.clear();
  for (size_t i = 0; i < ptrs.size(); ++i) {
    sorted.push_back(ptrs[i]->value);
  }
}

void PmergeMe::run(void) {
  clock_t start = clock();
  sortContainer<std::vector<int>, std::vector<ChainElement> >(origin_vector, sorted_vector);
  clock_t end = clock();
  time_vector = (double)(end - start) / CLOCKS_PER_SEC * MICROSECONDS_PER_SECOND;

  start = clock();
  sortContainer<std::deque<int>, std::deque<ChainElement> >(origin_deque, sorted_deque);
  end = clock();
  time_deque = (double)(end - start) / CLOCKS_PER_SEC * MICROSECONDS_PER_SECOND;
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

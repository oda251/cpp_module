#pragma once
#include <limits.h>

#include <algorithm>
#include <ctime>
#include <deque>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <iterator>

class PmergeMe {
 private:
  struct ChainElement {
    int value;
    std::vector<ChainElement*> losers;
    ChainElement(int v) : value(v) {}
  };

  std::vector<int> origin_vector;
  std::deque<int> origin_deque;
  std::vector<int> sorted_vector;
  std::deque<int> sorted_deque;
  double time_vector;
  double time_deque;

  struct ChainComparator {
    bool operator()(const ChainElement* a, const ChainElement* b) const {
      return a->value < b->value;
    }
  };

  // Internal Ford-Johnson implementation using ChainElement pointers
  template <typename Container>
  void fordJohnsonRecursive(Container& elements);

  // Helper to handle the top-level sort for different containers
  template <typename RawContainer, typename ElementContainer, typename PointerContainer>
  void sortContainer(RawContainer& raw, RawContainer& sorted);

  unsigned long long getJacobsthal(unsigned long long n);

 public:
  PmergeMe(int argc, char** argv);
  PmergeMe(const PmergeMe& other);
  PmergeMe& operator=(const PmergeMe& other);
  ~PmergeMe(void);

  void run(void);
  void printResults(void) const;
};

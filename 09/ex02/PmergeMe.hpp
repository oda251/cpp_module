#pragma once
#include <limits.h>

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

class PmergeMe {
 private:
  std::vector<int> origin_vector;
  std::deque<int> origin_deque;
  std::vector<int> sorted_vector;
  std::deque<int> sorted_deque;
  double time_vector;
  double time_deque;

  // Helper functions
  template <typename Container>
  void mergeInsertionSort(Container& arr);

  // Binary insert helper
  template <typename Container>
  typename Container::iterator binarySearch(typename Container::iterator begin,
                                            typename Container::iterator end,
                                            int value);

  unsigned long long getJacobsthal(unsigned long long n);

 public:
  PmergeMe(int argc, char** argv);
  PmergeMe(const PmergeMe& other);
  PmergeMe& operator=(const PmergeMe& other);
  ~PmergeMe(void);

  void run(void);
  void printResults(void) const;
};

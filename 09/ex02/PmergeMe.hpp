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

#define MAX_SIZE 3000

class PmergeMe {
 private:
  std::vector<int> origin_vector;
  std::deque<int> origin_deque;
  std::vector<int> sorted_vector;
  std::deque<int> sorted_deque;
  double time_vector;
  double time_deque;

  // Helper functions
  template <typename DataContainer, typename IntContainer>
  void mergeInsertionSort(DataContainer& arr, IntContainer& result);

  template <typename Container>
  int binaryInsert(Container& sorted, int value,
                   typename Container::iterator end);

  int jacobsthal(int n);
  std::vector<int> generateJacobsthalSequence(int n);

 public:
  PmergeMe(int argc, char** argv);
  PmergeMe(const PmergeMe& other);
  PmergeMe& operator=(const PmergeMe& other);
  ~PmergeMe(void);

  void run(void);
  void printResults(void) const;
};

typedef struct s_data {
  s_data* lh;
  s_data* rh;
  int value;
} t_data;

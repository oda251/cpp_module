#pragma once
#include <limits.h>

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

#define MAX_SIZE 3000

struct Node {
  int num;
  Node* large;
  Node* small;
};

class PmergeMe {
 public:
  enum class ContainerType {
    VECTOR,
    DEQUE
  };

 private:
  std::vector<int> origin_vector;
  std::deque<int> origin_deque;
  std::vector<int> sorted_vector;
  std::deque<int> sorted_deque;
  long long time_vector;
  long long time_deque;
  void interpret_args(int argc, char** argv, ContainerType type);

 public:
  PmergeMe(void);
  PmergeMe(const PmergeMe& other);
  PmergeMe& operator=(const PmergeMe& other);
  ~PmergeMe(void);
  void solve(ContainerType type);
};
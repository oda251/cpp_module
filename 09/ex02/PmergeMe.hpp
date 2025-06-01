#pragma once
#include <string>
#include <deque>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstdlib>
#include <ctime>

struct Node {
  int num;
  Node* large;
  Node* small;
};

template <typename Container>
void pmerge_me(Container& input, Container& output);

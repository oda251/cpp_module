#include <algorithm>
#include <iostream>
#include <vector>
#include <list>

struct Node {
  int num;
  Node* large;
  Node* small;
};

int jacobsthal(int n) {
  static std::vector<int> memo;
  if (memo.empty()) {
    memo.push_back(0);
    memo.push_back(1);
  }
  if (memo.size() <= n) {
    for (int i = memo.size(); i <= n; ++i) {
      memo.push_back(memo[i - 1] + 2 * memo[i - 2]);
    }
  }
  return memo[n];
}

template <typename Container>
void margeInsertSort(std::vector<Node>& prev, std::list<int>& dest) {
  std::vector<Node> next;
  // 行き
  for (int i = 0; i < prev.size(); ++i) {
    if (i % 2 == 0) {
      next.push_back(Node());
      next[i / 2].large = prev[i].large;
    } else {
      next[i / 2].small = prev[i].large;
      if (next[i / 2].small.num > next[i / 2].large.num) {
        std::swap(next[i / 2].small, next[i / 2].large);
      }
    }
  }
  margeInsertSort(next, dest);
  int prev_tgt = -1;
  for (int i = 0; prev_tgt > static_cast<int>(prev.size()); i++) {
    for (int j = jacobsthal(i); j > prev_tgt; --j) {
      if (j < prev.size()) {
        // insert
        int num = next[j].num;
        int pos = std::lower_bound(dest.begin(), dest.end(), num) - dest.begin();
        if (pos == dest.size() || dest[pos] != num) {
          dest.insert(dest.begin() + pos, num);
        }
      }
    }
    prev_tgt = jacobsthal(i);
  }
}

template <typename Container>
void solve(Container& src, Container& dest) {
  if (src.empty()) {
    return;
  }
  dest.clear();
  dest.reserve(src.size());
  Container::iterator it = src.begin();
  std::vector<Node> nodes(src.size());
  for (Container::iterator it = src.begin(); it != src.end(); ++it) {
    nodes.push_back({*it, it, nullptr});
  }
  std::list<int> dest_list;
  margeInsertSort(nodes, dest_list);
  for (auto& node : dest_list) {
    dest.push_back(node.num);
  }
};
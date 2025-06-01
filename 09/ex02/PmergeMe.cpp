#include "PmergeMe.hpp"


int Jacobsthal(int n) {
    static std::vector<int> memo = {0, 1};
    if (n < memo.size()) {
        return memo[n];
    }
    while (memo.size() <= n) {
        int next_value = memo[memo.size() - 1] + 2 * memo[memo.size() - 2];
        memo.push_back(next_value);
    }
}

template <typename Container>
void pmerge_me(Container& input, Container& output) {
    typename Container::iterator it = input.begin();
}

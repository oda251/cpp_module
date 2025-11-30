#include "PmergeMe.hpp"

#include <cctype>
#include <deque>
#include <iterator>
#include <list>
#include <map>

#define MICROSECONDS_PER_SECOND 1000000.0

s_data::s_data(int n) : larger(NULL), smaller(NULL), value(n) {}
bool s_data::operator<(const s_data& other) const {
  return this->value < other.value;
}
bool s_data::operator>(const s_data& other) const {
  return this->value > other.value;
}
s_data::s_data(s_data a, s_data b) {
  if (a.value > b.value) {
    this->larger = &a;
    this->smaller = &b;
    this->value = a.value;
  } else {
    this->larger = &b;
    this->smaller = &a;
    this->value = b.value;
  }
}

// コンストラクタ
PmergeMe::PmergeMe(int argc, char** argv) : time_vector(0), time_deque(0) {
  if (argc < 2) {
    throw std::invalid_argument("No arguments provided.");
  }
  if (argc > MAX_SIZE + 1) {
    std::ostringstream oss;
    oss << "Too many arguments provided. Maximum is " << MAX_SIZE;
    throw std::invalid_argument(oss.str());
  }

  std::stringstream ss;

  // 引数を解析して両方のコンテナに格納
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

// コピーコンストラクタ
PmergeMe::PmergeMe(const PmergeMe& other)
    : origin_vector(other.origin_vector),
      origin_deque(other.origin_deque),
      sorted_vector(other.sorted_vector),
      sorted_deque(other.sorted_deque),
      time_vector(other.time_vector),
      time_deque(other.time_deque) {}

// 代入演算子
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

// デストラクタ
PmergeMe::~PmergeMe(void) {}

// Jacobsthal数を計算
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

// 挿入順のための Jacobsthal シーケンスを生成
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

// 二分挿入：ソート順を維持して挿入
template <typename Container>
int PmergeMe::binaryInsert(Container& sorted, int value,
                           typename Container::iterator end) {
  typename Container::iterator pos =
      std::lower_bound(sorted.begin(), end, value);
  sorted.insert(pos, value);
  return std::distance(sorted.begin(), pos);
}

// Ford-Johnson（マージ挿入）ソートの実装
template <typename Container>
void PmergeMe::mergeInsertionSort(Container& arr) {
  size_t n = arr.size();

  // 基底ケース
  if (n <= 1) return;

  if (n == 2) {
    if (arr[0].value > arr[1].value) {
      std::swap(arr[0], arr[1]);
    }
    return;
  }

  // ステップ1: 上り；ペア作成
  std::vector<t_data> pairs;

  size_t pairCount = n / 2;
  pairs.reserve(pairCount);
  for (size_t i = 0; i < pairCount; ++i) {
    t_data a = arr[2 * i];
    t_data b = arr[2 * i + 1];
    // ここで大小比較を行い、ペアを作成
    t_data data(a, b);
    pairs.push_back(data);
  }

  // ステップ2: 下り；ペア展開
  if (!pairs.empty()) {
    // pairsがソートされて帰ってくる
    mergeInsertionSort(pairs);
    std::vector<int> largeIdxs;
    for (size_t i = 0; i < pairs.size(); ++i) {
      largeIdxs.push_back(i + 1);
    }

    Container result;
    result.push_back(*(pairs.begin()->smaller));

    std::vector<int> jacobSequence = generateJacobsthalSequence(pairs.size());

    size_t jacob_idx = 0;
    size_t jacob_cursor = 0;
    while (jacob_cursor < pairs.size()) {
      for (size_t i = jacob_cursor + jacobSequence[jacob_idx] - 1;
           i >= jacob_cursor; --i) {
        if (i >= pairs.size()) continue;
        int inserted_idx = binaryInsert<Container>(
            result, pairs[largeIdxs[i]].larger->value, result.end());
        for (size_t j = 0; j < largeIdxs.size(); ++j) {
          if (largeIdxs[j] >= inserted_idx) {
            largeIdxs[j]++;
          }
        }
      }
    }

    if (n % 2 == 1) {
      // 余りの要素がある場合は最後に挿入
      binaryInsert<Container>(result, arr[n - 1].value, result.end());
    }
  }
}

// 実際に両方のコンテナでソートを実行
void PmergeMe::run(void) {
  // std::vector でソート
  std::vector<t_data*> copied_vector;
  for (size_t i = 0; i < origin_vector.size(); ++i) {
    t_data* data = new t_data(origin_vector[i]);
    copied_vector.push_back(data);
  }
  clock_t start = clock();
  mergeInsertionSort(copied_vector);
  clock_t end = clock();
  time_vector =
      (double)(end - start) / CLOCKS_PER_SEC * MICROSECONDS_PER_SECOND;

  // std::deque でソート
  std::deque<t_data*> copied_deque;
  for (size_t i = 0; i < origin_deque.size(); ++i) {
    t_data* data = new t_data(origin_deque[i]);
    copied_deque.push_back(data);
  }
  start = clock();
  mergeInsertionSort(copied_deque);
  end = clock();
  time_deque = (double)(end - start) / CLOCKS_PER_SEC * MICROSECONDS_PER_SECOND;
}

// 結果を出力
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

// 明示的テンプレートインスタンス化
template void PmergeMe::mergeInsertionSort<std::vector<t_data> >(
    std::vector<t_data>&);
template void PmergeMe::mergeInsertionSort<std::deque<t_data> >(
    std::deque<t_data>&);
template int PmergeMe::binaryInsert<std::vector<int> >(
    std::vector<int>&, int, std::vector<int>::iterator);
template int PmergeMe::binaryInsert<std::deque<int> >(
    std::deque<int>&, int, std::deque<int>::iterator);

#include "PmergeMe.hpp"

#include <cctype>
<<<<<<< Updated upstream

#define MICROSECONDS_PER_SECOND 1000000.0

int CNT = 0;

// Constructor
=======
#include <deque>
#include <iterator>
#include <list>
#include <map>

#define MICROSECONDS_PER_SECOND 1000000.0

// コンストラクタ
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
  // Parse arguments and populate both containers
=======
  // 引数を解析して両方のコンテナに格納
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
// Copy constructor
=======
// コピーコンストラクタ
>>>>>>> Stashed changes
PmergeMe::PmergeMe(const PmergeMe& other)
    : origin_vector(other.origin_vector),
      origin_deque(other.origin_deque),
      sorted_vector(other.sorted_vector),
      sorted_deque(other.sorted_deque),
      time_vector(other.time_vector),
      time_deque(other.time_deque) {}

<<<<<<< Updated upstream
// Assignment operator
=======
// 代入演算子
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
// Destructor
PmergeMe::~PmergeMe(void) {}

// Calculate Jacobsthal number
=======
// デストラクタ
PmergeMe::~PmergeMe(void) {}

// Jacobsthal数を計算
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
// Generate Jacobsthal sequence for insertion order
=======
// 挿入順のための Jacobsthal シーケンスを生成
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
bool comp(int a, int b) {
  CNT++;
  return a < b;
}
// Binary insertion to maintain sorted order
template <typename Container>
void PmergeMe::binaryInsert(Container& sorted, int value,
                            typename Container::iterator end) {
  typename Container::iterator pos =
      std::lower_bound(sorted.begin(), end, value, comp);
=======

// 二分挿入：ソート順を維持して挿入
template <typename Container>
int PmergeMe::binaryInsert(Container& sorted, int value,
                           typename Container::iterator end) {
  typename Container::iterator pos =
      std::lower_bound(sorted.begin(), end, value);
>>>>>>> Stashed changes
  sorted.insert(pos, value);
  return std::distance(sorted.begin(), pos);
}

<<<<<<< Updated upstream
// Ford-Johnson merge insertion sort implementation
template <typename Container>
void PmergeMe::mergeInsertionSort(Container& arr) {
  size_t n = arr.size();

  // Base cases
  if (n <= 1) return;

  if (n == 2) {
    CNT++;
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
    CNT++;
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
    size_t j = i;
    while (j > 0 && pairs[j - 1].first > key.first) {
      pairs[j] = pairs[j - 1];
      --j;
    }
    pairs[j] = key;
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
    // Convert Jacobsthal number (1-based) to array index (0-based)
    int pos = jacobSequence[i] - 1;
    if (pos >= 0 && pos < static_cast<int>(pairs.size()) && !inserted[pos]) {
      // pairs[pos].second < pairs[pos].first, which is at index pos+1 in
      // mainChain
      typename Container::iterator endPos = mainChain.begin() + (pos + 2);
      binaryInsert(mainChain, pairs[pos].second, endPos);
      inserted[pos] = true;
    }

    // Insert elements between previous and current Jacobsthal number in reverse
    // Subtracting 2 accounts for: -1 for 0-based indexing and -1 to exclude
    // current position
    int prevJacob = (i == 0) ? 1 : jacobSequence[i - 1];
    for (int j = jacobSequence[i] - 2; j >= prevJacob; --j) {
      if (j >= 0 && j < static_cast<int>(pairs.size()) && !inserted[j]) {
        // pairs[j].second < pairs[j].first, which is at index j+1 in mainChain
        typename Container::iterator endPos = mainChain.begin() + (j + 2);
        binaryInsert(mainChain, pairs[j].second, endPos);
        inserted[j] = true;
      }
    }
  }

  // Insert any remaining elements
  for (size_t i = 0; i < pairs.size(); ++i) {
    if (!inserted[i]) {
      // pairs[i].second < pairs[i].first, which is at index i+1 in mainChain
      typename Container::iterator endPos = mainChain.begin() + (i + 2);
      binaryInsert(mainChain, pairs[i].second, endPos);
    }
  }

  // Insert straggler if exists
  if (hasStraggler) {
    // Straggler could be anywhere in the sorted sequence
    binaryInsert(mainChain, straggler, mainChain.end());
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
=======
// Ford-Johnson（マージ挿入）ソートの実装
template <typename DataContainer, typename IntContainer>
void PmergeMe::mergeInsertionSort(DataContainer& arr, IntContainer& result) {
  size_t n = arr.size();

  // 基底ケース
  if (n <= 1) return;

  if (n == 2) {
    if (arr[0].value > arr[1].value) {
      std::swap(arr[0], arr[1]);
    }
    return;
  }

  // ステップ1: ペアを作成して各ペアをソート
  std::vector<t_data> pairs;

  size_t pairCount = n / 2;
  pairs.reserve(pairCount);
  for (size_t i = 0; i < pairCount; ++i) {
    t_data a = arr[2 * i];
    t_data b = arr[2 * i + 1];
    t_data data;
    if (a.value > b.value) {
      data.lh = &a;
      data.rh = &b;
      data.value = a.value;
    } else {
      data.lh = &b;
      data.rh = &a;
      data.value = b.value;
    }
    pairs.push_back(data);
  }

  // ステップ2: ペアの "大きい方" によってソート
  // Ford‑Johnson の考え方に従い、まず大きい要素群を再帰的にソートし、
  // その順序に従ってペアを並べ替える（再帰ステップ）
  if (!pairs.empty()) {
    // 大きい要素群を再帰的にソート（Ford‑Johnson の再帰部分）
    mergeInsertionSort(pairs, result);

    result.insert(result.begin(), pairs.begin()->lh->value);
    std::vector<int> largeIdxs;
    for (size_t i = 0; i < pairs.size(); ++i) {
      largeIdxs.push_back(i + 1);
    }

    std::vector<int> jacobSequence = generateJacobsthalSequence(pairs.size());

    size_t jacob_idx = 0;
    size_t jacob_cursor = 0;
    while (jacob_cursor < pairs.size()) {
      for (size_t i = jacob_cursor + jacobSequence[jacob_idx] - 1;
           i >= jacob_cursor; --i) {
        if (i >= pairs.size()) continue;
        int inserted_idx = binaryInsert<IntContainer>(
            result, pairs[largeIdxs[i]].lh->value, result.end());
        for (size_t j = 0; j < largeIdxs.size(); ++j) {
          if (largeIdxs[j] >= inserted_idx) {
            largeIdxs[j]++;
          }
        }
      }
    }
  }

  if (n % 2 == 1) {
    // 余りの要素がある場合は最後に挿入
    binaryInsert<IntContainer>(result, arr[n - 1].value, result.end());
  }
}

// 実際に両方のコンテナでソートを実行
void PmergeMe::run(void) {
  // std::vector でソート
  std::vector<t_data> copied_vector;
  for (size_t i = 0; i < origin_vector.size(); ++i) {
    t_data data;
    data.value = origin_vector[i];
    copied_vector.push_back(data);
  }
  clock_t start = clock();
  mergeInsertionSort(copied_vector, sorted_vector);
>>>>>>> Stashed changes
  clock_t end = clock();
  time_vector =
      (double)(end - start) / CLOCKS_PER_SEC * MICROSECONDS_PER_SECOND;

<<<<<<< Updated upstream
  // Sort with deque
  sorted_deque = origin_deque;
  start = clock();
  mergeInsertionSort(sorted_deque);
=======
  // std::deque でソート
  std::deque<t_data> copied_deque;
  for (size_t i = 0; i < origin_deque.size(); ++i) {
    t_data data;
    data.value = origin_deque[i];
    copied_deque.push_back(data);
  }
  start = clock();
  mergeInsertionSort(copied_deque, sorted_deque);
>>>>>>> Stashed changes
  end = clock();
  time_deque = (double)(end - start) / CLOCKS_PER_SEC * MICROSECONDS_PER_SECOND;
}

<<<<<<< Updated upstream
// Print results
=======
// 結果を出力
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
  std::cout << CNT / 2 << std::endl;
}

// Explicit template instantiation
template void PmergeMe::mergeInsertionSort<std::vector<int> >(
    std::vector<int>&);
template void PmergeMe::mergeInsertionSort<std::deque<int> >(std::deque<int>&);
template void PmergeMe::binaryInsert<std::vector<int> >(
=======
}

// 明示的テンプレートインスタンス化
template void PmergeMe::mergeInsertionSort<std::vector<t_data> >(
    std::vector<t_data>&, std::vector<int>&);
template void PmergeMe::mergeInsertionSort<std::deque<t_data> >(
    std::deque<t_data>&, std::deque<int>&);
template int PmergeMe::binaryInsert<std::vector<int> >(
>>>>>>> Stashed changes
    std::vector<int>&, int, std::vector<int>::iterator);
template int PmergeMe::binaryInsert<std::deque<int> >(
    std::deque<int>&, int, std::deque<int>::iterator);

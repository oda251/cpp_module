#include <iostream>
#include "iter.hpp"

template <typename T>
void iter(T *array, size_t length, void (*func)(T&)) {
  for (size_t i = 0; i < length; i++) {
    func(array[i]);
  }
}

template <typename T>
void print(T &n) {
	std::cout << n << std::endl;
}

int main(void) {
	int array[] = {1, 2, 3, 4, 5};
	std::cout << "print int array {1, 2, 3, 4, 5}" << std::endl;
	iter(array, 5, print);
	std::string array2[] = {"one", "two", "three", "four", "five"};
	std::cout << "print string array {\"one\", \"two\", \"three\", \"four\", \"five\"}" << std::endl;
	iter(array2, 5, print);
	return 0;
}

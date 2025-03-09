#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**) {
  {
    int* a = new int();
    std::cout << "new int: " << *a << std::endl;
    delete a;
  }
  Array<int> numbers(MAX_VAL);
  int* mirror = new int[MAX_VAL];
  srand(time(NULL));
  for (int i = 0; i < MAX_VAL; i++) {
    const int value = rand();
    numbers[i] = value;
    mirror[i] = value;
  }
  // SCOPE
  {
    Array<int> tmp = numbers;
    Array<int> test(tmp);
  }

  for (int i = 0; i < MAX_VAL; i++) {
    if (mirror[i] != numbers[i]) {
      std::cerr << "didn't save the same value!!" << std::endl;
      return 1;
    }
  }
  try {
    std::cerr << "--- trying to access out of limits" << std::endl;
    numbers[-2] = 0;
    std::cerr << "didn't throw an exception!" << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  try {
    std::cerr << "--- trying to access out of limits" << std::endl;
    numbers[MAX_VAL] = 0;
    std::cerr << "didn't throw an exception!" << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  std::cerr << "--- copy then change original value" << std::endl;
  Array<int> copy = numbers;
  for (int i = 0; i < MAX_VAL; i++) {
    numbers[i] = rand();
  }
  for (int i = 0; i < MAX_VAL; i++) {
    if (copy[i] != mirror[i]) {
      std::cerr << "changing original array affected copied array!"
                << std::endl;
      return 1;
    }
  }
  std::cerr << "OK" << std::endl;

  delete[] mirror;  //
  return 0;
}
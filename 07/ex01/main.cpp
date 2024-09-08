#include <iostream>
#include "iter.hpp"

template<typename T>
void test(T val) {
	std::cout << val << std::endl;
}

int main() {
	unsigned int arr[] = {50, 51, 52, 53, 54, 55};
	std::cout << "--- int ---\n";
	iter(reinterpret_cast<int*>(arr), 5, test<int>);
	std::cout << "--- char ---\n";
	iter(reinterpret_cast<char*>(arr), 5, test<char>);
		std::cout << "--- float ---\n";
	iter(reinterpret_cast<float*>(arr), 5, test<float>);
	return (0);
}

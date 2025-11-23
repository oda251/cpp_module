#include <iostream>
#include <vector>
#include <algorithm>

// Copy the algorithm here for debugging
template <typename Container>
void printContainer(const Container& c, const std::string& label) {
    std::cout << label << ": ";
    for (size_t i = 0; i < c.size(); ++i) {
        std::cout << c[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> test;
    test.push_back(10);
    test.push_back(9);
    test.push_back(8);
    test.push_back(7);
    test.push_back(6);
    test.push_back(5);
    test.push_back(4);
    test.push_back(3);
    test.push_back(2);
    test.push_back(1);
    
    printContainer(test, "Before");
    
    // Use std::sort to verify expected result
    std::sort(test.begin(), test.end());
    
    printContainer(test, "After std::sort");
    
    return 0;
}

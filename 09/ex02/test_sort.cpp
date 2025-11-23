#include "PmergeMe.hpp"

int main(int argc, char** argv) {
  try {
    PmergeMe sorter(argc, argv);
    sorter.run();
    
    // Access private members for testing - we'll use printResults instead
    sorter.printResults();
    
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

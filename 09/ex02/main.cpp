#include "PmergeMe.hpp"
#include <cstdlib>

int main(int argc, char** argv) {
  try {
    PmergeMe sorter(argc, argv);
    sorter.run();
    sorter.printResults();
  } catch (const std::invalid_argument& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return EXIT_FAILURE;
  } catch (const std::exception& e) {
    std::cerr << "Unexpected error: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

#include <iostream>
#include "Brain.hpp"

Brain::Brain() {
	for (int i = 0; i < 100; i++)
		ideas[i] = "";
	std::cout << "Brain default constructor" << std::endl;
}
Brain::Brain(const Brain& other) {
	for (int i = 0; i < 100; i++)
		ideas[i] = other.getIdea(i);
	std::cout << "Brain copy constructor" << std::endl;
}
Brain::~Brain() {
	std::cout << "Brain destructor" << std::endl;
}
Brain& Brain::operator=(const Brain& other) {
	for (int i = 0; i < 100; i++)
		ideas[i] = other.getIdea(i);
	return *this;
}

void Brain::setIdea(const std::string& idea, int index) {
	ideas[index] = idea;
}
std::string Brain::getIdea(int index) const {
	return ideas[index];
}

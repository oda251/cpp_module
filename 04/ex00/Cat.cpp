#include <iostream>
#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat() : Animal("Cat") {}
Cat::Cat(const Cat& other) : Animal(other) {}
Cat::~Cat() {}

Cat& Cat::operator=(const Cat& other) {
	Animal::operator=(other);
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}

#include <iostream>
#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog() : Animal("Dog") {}
Dog::Dog(const Dog& other) : Animal(other) {}
Dog::~Dog() {}

void Dog::makeSound() const {
	std::cout << "Baw" << std::endl;
}

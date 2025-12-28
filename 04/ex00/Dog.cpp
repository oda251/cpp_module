#include <iostream>
#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog default constructor" << std::endl;
}
Dog::Dog(const Animal& other) : Animal(other) {
	std::cout << "Dog copy constructor" << std::endl;
}
Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog copy constructor" << std::endl;
}
Dog::~Dog() {
	std::cout << "Dog destructor" << std::endl;
}
Dog& Dog::operator=(const Dog& other) {
	Animal::operator=(other);
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Baw" << std::endl;
}

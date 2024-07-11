#include <iostream>
#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat default constructor" << std::endl;
}
Cat::Cat(const Animal& other) : Animal(other) {
	std::cout << "Cat copy constructor" << std::endl;
}
Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Cat copy constructor" << std::endl;
}
Cat::~Cat() {
	std::cout << "Cat destructor" << std::endl;
}
Cat& Cat::operator=(const Cat& other) {
	Animal::operator=(other);
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}

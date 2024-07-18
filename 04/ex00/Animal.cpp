#include <iostream>
#include "Animal.hpp"

Animal::Animal(void) : _type("") {
	std::cout << "Animal default constructor" << std::endl;
}
Animal::Animal(std::string type) : _type(type) {
	std::cout << "Animal constructor with type" << std::endl;
}
Animal::Animal(const Animal& other) : _type(other._type) {
	std::cout << "Animal copy constructor" << std::endl;
}
Animal::~Animal() {
	std::cout << "Animal destructor" << std::endl;
}
Animal& Animal::operator=(const Animal& other) {
	if (this != &other)
		_type = other._type;
	return *this;
}

std::string Animal::getType() const {
	return _type;
}
void Animal::setType(const std::string& type) {
	_type = type;
}
void Animal::makeSound() const {
	std::cout << std::endl;
}

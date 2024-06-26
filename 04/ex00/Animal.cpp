#include <iostream>
#include "Animal.hpp"

Animal::Animal(void) : _type("") {}
Animal::Animal(std::string type) : _type(type) {}
Animal::Animal(const Animal& other) : _type(other._type) {}
Animal::~Animal() {}
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
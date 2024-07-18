#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	std::cout << "WrongAnimal default constructor" << std::endl;
}
WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << "WrongAnimal constructor with type" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	_type = other._type;
	std::cout << "WrongAnimal copy constructor" << std::endl;
}
WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor" << std::endl;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other)
		_type = other._type;
	return *this;
}

std::string WrongAnimal::getType() const {
	return _type;
}
void WrongAnimal::setType(const std::string& type) {
	_type = type;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal sound" << std::endl;
}

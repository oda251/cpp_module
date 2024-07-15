#include <iostream>
#include "AbstractAnimal.hpp"

AbstractAnimal::AbstractAnimal(void) : _type("") {
	std::cout << "AbstractAnimal default constructor" << std::endl;
}
AbstractAnimal::AbstractAnimal(std::string type) : _type(type) {
	std::cout << "AbstractAnimal constructor with type" << std::endl;
}
AbstractAnimal::AbstractAnimal(const AbstractAnimal& other) : _type(other._type) {
	std::cout << "AbstractAnimal copy constructor" << std::endl;
}
AbstractAnimal::~AbstractAnimal() {
	std::cout << "AbstractAnimal destructor" << std::endl;
}
AbstractAnimal& AbstractAnimal::operator=(const AbstractAnimal& other) {
	if (this != &other)
		_type = other._type;
	return *this;
}

std::string AbstractAnimal::getType() const {
	return _type;
}
void AbstractAnimal::setType(const std::string& type) {
	_type = type;
}
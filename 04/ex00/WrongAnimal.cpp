#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : Animal() {}
WrongAnimal::WrongAnimal(std::string type) : Animal(type) {}
WrongAnimal::WrongAnimal(const WrongAnimal& other) : Animal(other) {}
WrongAnimal::~WrongAnimal() {}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	Animal::operator=(other);
	return *this;
}

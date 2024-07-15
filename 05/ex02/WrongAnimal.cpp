#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : Animal() {
	std::cout << "WrongAnimal default constructor" << std::endl;
}
WrongAnimal::WrongAnimal(std::string type) : Animal(type) {
	std::cout << "WrongAnimal constructor with type" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& other) : Animal(other) {
	std::cout << "WrongAnimal copy constructor" << std::endl;
}
WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor" << std::endl;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	Animal::operator=(other);
	return *this;
}

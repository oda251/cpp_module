#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat default constructor" << std::endl;
}
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	std::cout << "WrongCat copy constructor" << std::endl;
}
WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor" << std::endl;
}
WrongCat& WrongCat::operator=(const WrongCat& other) {
	WrongAnimal::operator=(other);
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "Bark" << std::endl;
}

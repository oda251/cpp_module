#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {}
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {}
WrongCat::~WrongCat() {}
WrongCat& WrongCat::operator=(const WrongCat& other) {
	WrongAnimal::operator=(other);
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "Bark" << std::endl;
}

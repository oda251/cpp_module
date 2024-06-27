#include <iostream>
#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog() : Animal("Dog") {
	brain = new Brain();
	std::cout << "Dog default constructor" << std::endl;
}
Dog::Dog(const Dog& other) : Animal(other) {
	brain = new Brain(*other.brain);
	std::cout << "Dog copy constructor" << std::endl;
}
Dog::~Dog() {
	delete brain;
	std::cout << "Dog destructor" << std::endl;
}
Dog& Dog::operator=(const Dog& other) {
	Animal::operator=(other);
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Baw" << std::endl;
}

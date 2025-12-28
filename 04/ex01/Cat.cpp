#include <iostream>
#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat() : Animal("Cat") {
	brain = new Brain();
	std::cout << "Cat default constructor" << std::endl;
}
Cat::Cat(const Cat& other) : Animal(other) {
	brain = new Brain(*other.brain);
	std::cout << "Cat copy constructor" << std::endl;
}
Cat::~Cat() {
	delete brain;
	std::cout << "Cat destructor" << std::endl;
}
Cat& Cat::operator=(const Cat& other) {
	Animal::operator=(other);
	*brain = *other.brain;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}

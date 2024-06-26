#include <iostream>
#include <string>
#include <cstdlib>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

__attribute__((destructor))
void    destructor(void)
{
	#ifdef LEAKS
	std::cout << "--- Destructor ---" << std::endl;
	system(LEAKS);
	#endif
}

int main(void) {
	const Animal* meta = new Animal();
	if (meta->getType().empty())
		std::cout << "Type is empty" << std::endl;
	else
		std::cout << "Type is not empty" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << "Dog makeSound: ";
	i->makeSound();
	std::cout << "Cat makeSound: ";
	j->makeSound();
	std::cout << "Animal makeSound: ";
	meta->makeSound();
	delete i;
	delete j;
	delete meta;

	i = new WrongCat();
	std::cout << i->getType() << " " << std::endl;
	std::cout << "WrongCat makeSound: ";
	i->makeSound();
	return 0;
}

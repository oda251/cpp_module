#include <iostream>
#include <string>
#include <cstdlib>
#include "Animal.hpp"

__attribute__((destructor))
void    destructor(void)
{
	#ifdef LEAKS
	std::cout << "--- Destructor ---" << std::endl;
	system(LEAKS);
	#endif
}

// #include "Dog.hpp"
int main(void) {
	// inability to instantiate abstract-class test
	Animal a;

	// Animal *a = new Dog();
	// a->makeSound();

	return 0;
}

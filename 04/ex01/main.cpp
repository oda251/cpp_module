#include <iostream>
#include <string>
#include <cstdlib>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

__attribute__((destructor))
void    destructor(void)
{
	#ifdef LEAKS
	std::cout << "--- Destructor ---" << std::endl;
	system(LEAKS);
	#endif
}

int main(void) {
	Animal* arr[10];

	for (int i=0; i<10; i++) {
		if (i < 5)
			arr[i] = new Dog();
		else
			arr[i] = new Cat();
	}

	for (int i=0; i<10; i++) {
		delete arr[i];
	}

	return 0;
}

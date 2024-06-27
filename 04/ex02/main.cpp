#include <iostream>
#include <string>
#include <cstdlib>
#include "AbstractAnimal.hpp"
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
	AbstractAnimal a;

	return 0;
}

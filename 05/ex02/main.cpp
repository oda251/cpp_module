#include <iostream>
#include <string>
#include <cstdlib>
#include "AbstractAnimal.hpp"

__attribute__((destructor))
void    destructor(void)
{
	#ifdef LEAKS
	std::cout << "--- Destructor ---" << std::endl;
	system(LEAKS);
	#endif
}

int main(void) {
	std::cout << "--- inability to instantiate abstract-class test ---";
	AbstractAnimal a;

	return 0;
}

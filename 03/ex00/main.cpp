#include <iostream>
#include <string>
#include <cstdlib>
#include "ClapTrap.hpp"

__attribute__((destructor))
void    destructor(void)
{
	#ifdef LEAKS
	std::cout << "--- Destructor ---" << std::endl;
	system(LEAKS);
	#endif
}

int main(void) {
	ClapTrap defaultTrap;
	ClapTrap nameTrap("Bob");
	ClapTrap copyTrap(nameTrap);

	nameTrap.attack("target");
	nameTrap.takeDamage(5);
	nameTrap.beRepaired(5);
	copyTrap.attack("target");
	copyTrap.takeDamage(5);
	copyTrap.beRepaired(5);
	std::cout << "--- Bob take extra damage ---" << std::endl;
	copyTrap.takeDamage(100);
	std::cout << "--- Dead Bob try to be repaired ---" << std::endl;
	copyTrap.beRepaired(5);
	std::cout << "--- Default try to attach 11 times ---" << std::endl;
	for (int i = 0; i < 11; i++)
		defaultTrap.attack("target");
	
	return 0;
}

#include <iostream>
#include <string>
#include <cstdlib>
#include "ScavTrap.hpp"

__attribute__((destructor))
void    destructor(void)
{
	#ifdef LEAKS
	std::cout << "--- Destructor ---" << std::endl;
	system(LEAKS);
	#endif
}

int main(void) {
	ScavTrap defaultTrap;
	ScavTrap nameTrap("Bob");
	ScavTrap copyTrap(nameTrap);

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
	std::cout << "--- Default enter gate-keeper mode ---" << std::endl;
	defaultTrap.guardGate();
	std::cout << "--- Default exit gate-keeper mode ---" << std::endl;
	defaultTrap.guardGate();
	
	return 0;
}

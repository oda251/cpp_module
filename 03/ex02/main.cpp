#include <iostream>
#include <string>
#include <cstdlib>
#include "FragTrap.hpp"

__attribute__((destructor))
void    destructor(void)
{
	#ifdef LEAKS
	std::cout << "--- Destructor ---" << std::endl;
	system(LEAKS);
	#endif
}

int main(void) {
	FragTrap defaultTrap;
	FragTrap nameTrap("Bob");
	FragTrap copyTrap(nameTrap);

	nameTrap.attack("target");
	nameTrap.takeDamage(5);
	nameTrap.beRepaired(5);
	copyTrap.attack("target");
	copyTrap.takeDamage(5);
	copyTrap.beRepaired(5);
	std::cout << "--- Bob's HP is ---" << std::endl;
	std::cout << nameTrap.getHitPoints() << std::endl;
	std::cout << "--- Bob's EP is ---" << std::endl;
	std::cout << nameTrap.getEnergyPoints() << std::endl;
	std::cout << "--- Bob ATK is ---" << std::endl;
	std::cout << nameTrap.getAttackDamage() << std::endl;
	std::cout << "--- highFivesGuys ---" << std::endl;
	defaultTrap.highFivesGuys();
	
	return 0;
}

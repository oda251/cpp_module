#include <iostream>
#include <string>
#include <cstdlib>
#include "DiamondTrap.hpp"

__attribute__((destructor))
void    destructor(void)
{
	#ifdef LEAKS
	std::cout << "--- Destructor ---" << std::endl;
	system(LEAKS);
	#endif
}

int main(void) {
	DiamondTrap trap;
	DiamondTrap nameTrap("Bob");

	std::cout << "--- Bob's HP is ---" << std::endl;
	std::cout << nameTrap.getHitPoints() << std::endl;
	std::cout << "--- Bob's EP is ---" << std::endl;
	std::cout << nameTrap.getEnergyPoints() << std::endl;
	std::cout << "--- Bob ATK is ---" << std::endl;
	std::cout << nameTrap.getAttackDamage() << std::endl;
	std::cout << "--- Bot attack target ---" << std::endl;
	nameTrap.attack("target");
	std::cout << "--- Bot whoAmI ---" << std::endl;
	nameTrap.whoAmI();
	
	return 0;
}

#include <iostream>
#include <string>
#include <cstdlib>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

__attribute__((destructor))
void    destructor(void)
{
	#ifdef LEAKS
	std::cout << "--- Destructor ---" << std::endl;
	system(LEAKS);
	#endif
}

int main(void) {
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();
	AMateria* tmp = NULL;
	Character bob("bob");
	MateriaSource src;

	std::cout << "--- learnMateria -> equip -> use -> unequip ---" << std::endl;
	src.learnMateria(ice);
	src.learnMateria(cure);
	delete ice;
	delete cure;
	bob.equip(src.createMateria("ice"));
	bob.equip(src.createMateria("cure"));
	bob.use(0, bob);
	bob.use(1, bob);
	tmp = bob.getMateria(0);
	bob.unequip(0);
	delete tmp;
	tmp = bob.getMateria(1);
	bob.unequip(1);
	delete tmp;

	std::cout << "--- use unequiped materia ---" << std::endl;
	bob.use(0, bob);
	bob.use(1, bob);

	std::cout << "--- verify deep-copied ---" << std::endl;
	bob.equip(src.createMateria("ice"));
	Character ben(bob);
	ben.setName("ben");
	bob.destroyEquipment(0);
	ben.use(0, ben);

	return 0;
}

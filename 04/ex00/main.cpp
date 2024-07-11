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
	Animal* meta = new Animal();
	Animal* j = new Dog();
	Animal* i = new Cat();
	WrongAnimal* k = new WrongAnimal();
	WrongAnimal* l = new WrongCat();
	Animal* c;

	std::cout << "--- type ---" << std::endl;
	std::cout << "Animal: " << meta->getType() << std::endl;
	std::cout << "Dog: " << j->getType() << std::endl;
	std::cout << "Cat: " << i->getType() << std::endl;
	std::cout << "WrongAnimal: " << k->getType() << std::endl;
	std::cout << "WrongCat: " << l->getType() << std::endl;
	std::cout << std::endl;

	std::cout << "--- setType ---" << std::endl;
	std::cout << "Animal setType: ";
	meta->setType("T1");
	std::cout << meta->getType() << std::endl;
	std::cout << "Dog setType: ";
	j->setType("T2");
	std::cout << j->getType() << std::endl;
	std::cout << "Cat setType: ";
	i->setType("T3");
	std::cout << i->getType() << std::endl;
	std::cout << "WrongAnimal setType: ";
	k->setType("T4");
	std::cout << k->getType() << std::endl;
	std::cout << "WrongCat setType: ";
	std::cout << std::endl;

	std::cout << "--- copy constructor ---" << std::endl;
	std::cout << "Animal copy constructor: ";
	c = new Animal(*meta);
	std::cout << c->getType() << std::endl;
	delete c;
	std::cout << "Dog copy constructor: ";
	c = new Dog(*j);
	std::cout << c->getType() << std::endl;
	delete c;
	std::cout << "Cat copy constructor: ";
	c = new Cat(*i);
	std::cout << c->getType() << std::endl;
	delete c;
	std::cout << "WrongAnimal copy constructor: ";
	c = new WrongAnimal(*k);
	std::cout << c->getType() << std::endl;
	delete c;
	std::cout << "WrongCat copy constructor: ";
	c = new WrongCat(*l);
	std::cout << c->getType() << std::endl;
	delete c;
	std::cout << std::endl;

	std::cout << "--- makeSound ---" << std::endl;
	std::cout << "Animal makeSound: ";
	meta->makeSound();
	delete meta;
	std::cout << "Dog makeSound: ";
	j->makeSound();
	delete j;
	std::cout << "Cat makeSound: ";
	i->makeSound();
	delete i;
	std::cout << "WrongAnimal makeSound: ";
	k->makeSound();
	delete k;
	std::cout << "WrongCat makeSound: ";
	l->makeSound();
	delete l;

	return 0;
}

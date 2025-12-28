#include <iostream>
#include "AMateria.hpp"
#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}
Cure::Cure(Cure const &cure) : AMateria(cure) {}
Cure &Cure::operator=(Cure const &cure) {
	_type = cure.getType();
	return *this;
}
Cure::~Cure() {}
std::string const &Cure::getType() const {
	return _type;
}
void Cure::setType(std::string const &type) {
	_type = type;
}
AMateria* Cure::clone() const {
	return new Cure(*this);
}
void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

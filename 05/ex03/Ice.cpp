#include <iostream>
#include "Ice.hpp"

Ice::Ice() {
	setType("ice");
}
Ice::Ice(Ice const &ice) {
	*this = ice;
}
Ice &Ice::operator=(Ice const &ice) {
	_type = ice.getType();
	return *this;
}
Ice::~Ice() {}
std::string const &Ice::getType() const {
	return _type;
}
void Ice::setType(std::string const &type) {
	_type = type;
}
AMateria* Ice::clone() const {
	return new Ice(*this);
}
void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

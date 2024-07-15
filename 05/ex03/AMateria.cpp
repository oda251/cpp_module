#include "AMateria.hpp"

AMateria::AMateria(void) : _type("default") {}
AMateria::AMateria(std::string const & type) : _type(type) {}
AMateria::AMateria(AMateria const & src) {
	*this = src;
}
AMateria & AMateria::operator=(AMateria const & src) {
	_type = src.getType();
	return *this;
}
AMateria::~AMateria() {}
#include "Weapon.hpp"

Weapon::Weapon(void) {
	_type = "no_name";
}

Weapon::Weapon(std::string type) {
	_type = type;
}

const std::string &Weapon::getType(void) {
	return (_type);
}

void Weapon::setType(std::string type) {
	_type = type;
}

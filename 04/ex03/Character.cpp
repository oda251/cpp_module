#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(std::string const & name) : _name(name) {
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}
Character::Character(Character const & src) {
	*this = src;
}
Character & Character::operator=(Character const & src) {
	_name = src.getName();
	for (int i = 0; i < 4; i++) {
		if (_inventory[i]) {
			delete _inventory[i];
			_inventory[i] = NULL;
		}
		if (src.getMateria(i))
			_inventory[i] = src.getMateria(i)->clone();
		else
			_inventory[i] = NULL;
	}
	return *this;
}
Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i])
			delete _inventory[i];
	}
}
const std::string& Character::getName() const {
	return _name;
}
void Character::setName(std::string const & _name) {
	this->_name = _name;
}
AMateria *Character::getMateria(int idx) const {
	if (idx >= 0 && idx < 4)
		return _inventory[idx];
	return NULL;
}
void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (!_inventory[i]) {
			_inventory[i] = m;
			break;
		}
	}
}
// it does not delete the materia
void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4)
		_inventory[idx] = NULL;
}
void Character::destroyEquipment(int idx) {
	if (idx >= 0 && idx < 4 && _inventory[idx]) {
		delete _inventory[idx];
		_inventory[idx] = NULL;
	}
}
void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && _inventory[idx])
		_inventory[idx]->use(target);
}

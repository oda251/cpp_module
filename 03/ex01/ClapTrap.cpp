#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
	_name("Default"),
	_maxHitPoints(_defaultMaxHitPoints),
	_maxEnergyPoints(_defaultMaxEnergyPoints),
	_hitPoints(_maxHitPoints),
	_energyPoints(_maxEnergyPoints),
	_attackDamage(_defaultAttackDamage)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}
ClapTrap::ClapTrap(const std::string &name) :
	_name(name),
	_maxHitPoints(_defaultMaxHitPoints),
	_maxEnergyPoints(_defaultMaxEnergyPoints),
	_hitPoints(_maxHitPoints),
	_energyPoints(_maxEnergyPoints),
	_attackDamage(_defaultAttackDamage)
{
	std::cout << "ClapTrap::" << _name << " Name constructor called" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &src) :
	_name(src._name),
	_maxHitPoints(src._maxHitPoints),
	_maxEnergyPoints(src._maxEnergyPoints),
	_hitPoints(src._hitPoints),
	_energyPoints(src._energyPoints),
	_attackDamage(src._attackDamage)
{
	std::cout << "ClapTrap::" << src._name << " Copy constructor called" << std::endl;
}
ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap::" << _name << " Destructor called" << std::endl;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &src) {
    std::cout << "= called" << std::endl;
    _name = src._name;
    _hitPoints = src._hitPoints;
    _energyPoints = src._energyPoints;
    _attackDamage = src._attackDamage;
    return *this;
}

bool ClapTrap::isAlive(void) const {
    if (_hitPoints == 0) {
        std::cout << _name << " has been broken!" << std::endl;
        return false;
    }
	return true;
}
bool ClapTrap::loseEnergy(void) {
	if (_energyPoints == 0) {
		std::cout << _name << " has no energy!" << std::endl;
		return false;
	}
	_energyPoints--;
	return true;
}

std::string ClapTrap::getName(void) const {
	return _name;
}
unsigned int ClapTrap::getMaxHitPoints(void) const {
	return _maxHitPoints;
}
unsigned int ClapTrap::getMaxEnergyPoints(void) const {
	return _maxEnergyPoints;
}
unsigned int ClapTrap::getHitPoints(void) const {
	return _hitPoints;
}
unsigned int ClapTrap::getEnergyPoints(void) const {
	return _energyPoints;
}
unsigned int ClapTrap::getAttackDamage(void) const {
	return _attackDamage;
}

bool ClapTrap::setName(const std::string &name) {
	if (name.empty()) {
		std::cout << "Name cannot be empty!" << std::endl;
		return false;
	}
	_name = name;
	return true;
}
bool ClapTrap::setMaxHitPoints(unsigned int maxHitPoints) {
	if (maxHitPoints < 0) {
		std::cout << "Max hit points cannot be negative!" << std::endl;
		return false;
	}
	_maxHitPoints = maxHitPoints;
	if (_hitPoints > _maxHitPoints) {
		_hitPoints = _maxHitPoints;
	}
	return true;
}
bool ClapTrap::setMaxEnergyPoints(unsigned int maxEnergyPoints) {
	if (maxEnergyPoints < 0) {
		std::cout << "Max energy points cannot be negative!" << std::endl;
		return false;
	}
	_maxEnergyPoints = maxEnergyPoints;
	if (_energyPoints > _maxEnergyPoints) {
		_energyPoints = _maxEnergyPoints;
	}
	return true;
}
bool ClapTrap::setHitPoints(unsigned int hitPoints) {
	if (hitPoints < 0) {
		std::cout << "Hit points cannot be negative!" << std::endl;
		return false;
	}
	_hitPoints = hitPoints;
	return true;
}
bool ClapTrap::setEnergyPoints(unsigned int energyPoints) {
	if (energyPoints < 0) {
		std::cout << "Energy points cannot be negative!" << std::endl;
		return false;
	} else if (energyPoints > _maxEnergyPoints) {
		std::cout << "Energy points cannot be greater than max energy points!" << std::endl;
		return false;
	}
	_energyPoints = energyPoints;
	return true;
}
bool ClapTrap::setAttackDamage(unsigned int attackDamage) {
	if (attackDamage < 0) {
		std::cout << "Attack damage cannot be negative!" << std::endl;
		return false;
	}
	_attackDamage = attackDamage;
	return true;
}

void ClapTrap::attack(const std::string &target) {
	if (!isAlive() || !loseEnergy())
		return;
    std::cout << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount) {
    if (amount == 0) {
        std::cout << _name << " has arleady broken!" << std::endl;
        return;
    }
    if (_hitPoints < amount) {
        std::cout << _name << " took " << _hitPoints << " points of damage!" << std::endl;
        _hitPoints = 0;
        std::cout << _name << " broke!" << std::endl;
    } else {
        std::cout << _name << " took " << amount << " points of damage!" << std::endl;
        _hitPoints -= amount;
    }
}
void ClapTrap::beRepaired(unsigned int amount) {
	if (!isAlive() || !loseEnergy())
		return;
    if (_hitPoints == _maxHitPoints) {
        std::cout << _name << " is already fully repaired!" << std::endl;
        return;
    }
    if (_hitPoints + amount > _maxHitPoints) {
        std::cout << _name << " was repaired by " << _maxHitPoints - _hitPoints << " points!" << std::endl;
        _hitPoints = _maxHitPoints;
        std::cout << _name << " is fully repaired!" << std::endl;
    } else {
        std::cout << _name << " was repaired by " << amount << " points!" << std::endl;
        _hitPoints += amount;
    }
}

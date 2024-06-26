#include "ScavTrap.hpp"

ScavTrap::ScavTrap() :
	_name("Default"),
	_maxHitPoints(_defaultMaxHitPoints),
	_maxEnergyPoints(_defaultMaxEnergyPoints),
	_hitPoints(_maxHitPoints),
	_energyPoints(_maxEnergyPoints),
	_attackDamage(_defaultAttackDamage)
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
}
ScavTrap::ScavTrap(const std::string &name) :
	_name(name),
	_maxHitPoints(_defaultMaxHitPoints),
	_maxEnergyPoints(_defaultMaxEnergyPoints),
	_hitPoints(_maxHitPoints),
	_energyPoints(_maxEnergyPoints),
	_attackDamage(_defaultAttackDamage)
{
	std::cout << "ScavTrap::" << _name << " Name constructor called" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &src) :
	_name(src._name),
	_maxHitPoints(src._maxHitPoints),
	_maxEnergyPoints(src._maxEnergyPoints),
	_hitPoints(src._hitPoints),
	_energyPoints(src._energyPoints),
	_attackDamage(src._attackDamage)
{
	std::cout << "ScavTrap::" << src._name << " Copy constructor called" << std::endl;
}
ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap::" << _name << " Destructor called" << std::endl;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &src) {
    std::cout << "= called" << std::endl;
    _name = src._name;
    _hitPoints = src._hitPoints;
    _energyPoints = src._energyPoints;
    _attackDamage = src._attackDamage;
    return *this;
}

bool ScavTrap::isAlive(void) const {
    if (_hitPoints == 0) {
        std::cout << _name << " has been broken!" << std::endl;
        return false;
    }
	return true;
}
bool ScavTrap::loseEnergy(void) {
	if (_energyPoints == 0) {
		std::cout << _name << " has no energy!" << std::endl;
		return false;
	}
	_energyPoints--;
	return true;
}

std::string ScavTrap::getName(void) const {
	return _name;
}
unsigned int ScavTrap::getMaxHitPoints(void) const {
	return _maxHitPoints;
}
unsigned int ScavTrap::getMaxEnergyPoints(void) const {
	return _maxEnergyPoints;
}
unsigned int ScavTrap::getHitPoints(void) const {
	return _hitPoints;
}
unsigned int ScavTrap::getEnergyPoints(void) const {
	return _energyPoints;
}
unsigned int ScavTrap::getAttackDamage(void) const {
	return _attackDamage;
}

bool ScavTrap::setName(const std::string &name) {
	if (name.empty()) {
		std::cout << "Name cannot be empty!" << std::endl;
		return false;
	}
	_name = name;
	return true;
}
bool ScavTrap::setMaxHitPoints(unsigned int maxHitPoints) {
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
bool ScavTrap::setMaxEnergyPoints(unsigned int maxEnergyPoints) {
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
bool ScavTrap::setHitPoints(unsigned int hitPoints) {
	if (hitPoints < 0) {
		std::cout << "Hit points cannot be negative!" << std::endl;
		return false;
	}
	_hitPoints = hitPoints;
	return true;
}
bool ScavTrap::setEnergyPoints(unsigned int energyPoints) {
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
bool ScavTrap::setAttackDamage(unsigned int attackDamage) {
	if (attackDamage < 0) {
		std::cout << "Attack damage cannot be negative!" << std::endl;
		return false;
	}
	_attackDamage = attackDamage;
	return true;
}

void ScavTrap::attack(const std::string &target) {
	if (!isAlive() || !loseEnergy())
		return;
    std::cout << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}
void ScavTrap::takeDamage(unsigned int amount) {
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
void ScavTrap::beRepaired(unsigned int amount) {
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
void ScavTrap::guardGate(void) {
	if (!isAlive() || !loseEnergy())
		return;
	if (_gateKeeperMode) {
		std::cout << _name << " has exited gate keeper mode!" << std::endl;
		_gateKeeperMode = false;
	} else {
		std::cout << _name << " has entered gate keeper mode!" << std::endl;
		_gateKeeperMode = true;
	}
}

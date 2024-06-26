#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() :
	FragTrap(),
	ScavTrap(),
	_maxHitPoints(FragTrap::getMaxHitPoints()),
	_maxEnergyPoints(ScavTrap::getMaxEnergyPoints()),
	_hitPoints(FragTrap::getMaxHitPoints()),
	_energyPoints(ScavTrap::getMaxEnergyPoints()),
	_attackDamage(FragTrap::getAttackDamage())
{
	setName("DiamondTrap"),
    std::cout << "DiamondTrap Default constructor called" << std::endl;
}
DiamondTrap::DiamondTrap(const std::string &name) :
	FragTrap(name),
	ScavTrap(name),
	_maxHitPoints(FragTrap::getMaxHitPoints()),
	_maxEnergyPoints(ScavTrap::getMaxEnergyPoints()),
	_hitPoints(FragTrap::getMaxHitPoints()),
	_energyPoints(ScavTrap::getMaxEnergyPoints()),
	_attackDamage(FragTrap::getAttackDamage())
{
	setName(name),
	std::cout << "DiamondTrap::" << name << " Name constructor called" << std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap &src) :
	FragTrap(),
	ScavTrap(),
	_maxHitPoints(src.getMaxHitPoints()),
	_maxEnergyPoints(src.getMaxEnergyPoints()),
	_hitPoints(src.getHitPoints()),
	_energyPoints(src.getEnergyPoints()),
	_attackDamage(src.getAttackDamage())
{
	setName(src.getName()),
    std::cout << "DiamondTrap::" << src.getName() << " Copy constructor called" << std::endl;
}
DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap::" << getName() << " Destructor called" << std::endl;
}

std::string DiamondTrap::getName(void) const {
	return _name;
}
unsigned int DiamondTrap::getMaxHitPoints(void) const {
	return _maxHitPoints;
}
unsigned int DiamondTrap::getMaxEnergyPoints(void) const {
	return _maxEnergyPoints;
}
unsigned int DiamondTrap::getHitPoints(void) const {
	return _hitPoints;
}
unsigned int DiamondTrap::getEnergyPoints(void) const {
	return _energyPoints;
}
unsigned int DiamondTrap::getAttackDamage(void) const {
	return _attackDamage;
}

bool DiamondTrap::setName(const std::string &name) {
	_name = name;
	ClapTrap::setName(name + "_clap_name");
	return true;
}
bool DiamondTrap::setHitPoints(unsigned int hitPoints) {
	_hitPoints = hitPoints;
	return true;
}
bool DiamondTrap::setEnergyPoints(unsigned int energyPoints) {
	_energyPoints = energyPoints;
	return true;
}
bool DiamondTrap::setAttackDamage(unsigned int attackDamage) {
	_attackDamage = attackDamage;
	return true;
}
bool DiamondTrap::setMaxHitPoints(unsigned int maxHitPoints) {
	_maxHitPoints = maxHitPoints;
	return true;
}
bool DiamondTrap::setMaxEnergyPoints(unsigned int maxEnergyPoints) {
	_maxEnergyPoints = maxEnergyPoints;
	return true;
}

void DiamondTrap::attack(const std::string &target) {
	FragTrap::attack(target);
}

void DiamondTrap::whoAmI(void) {
	std::cout << "DiamondTrap::" << getName() << " ClapTrap::" << ClapTrap::getName() << std::endl;
}

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	setName("FragTrap");
	setMaxEnergyPoints(FragTrap::_maxEnergyPoints);
	setMaxHitPoints(FragTrap::_maxHitPoints);
	setHitPoints(FragTrap::_maxHitPoints);
	setEnergyPoints(FragTrap::_maxEnergyPoints);
	setAttackDamage(FragTrap::_defaultAttackDamage);
    std::cout << "FragTrap Default constructor called" << std::endl;
}
FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	setMaxEnergyPoints(FragTrap::_maxEnergyPoints);
	setMaxHitPoints(FragTrap::_maxHitPoints);
	setHitPoints(FragTrap::_maxHitPoints);
	setEnergyPoints(FragTrap::_maxEnergyPoints);
	setAttackDamage(FragTrap::_defaultAttackDamage);
    std::cout << "FragTrap::" << getName() << " Name constructor called" << std::endl;
}
FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src) {
    std::cout << "FragTrap::" << src.getName() << " Copy constructor called" << std::endl;
}
FragTrap::~FragTrap() {
    std::cout << "FragTrap::" << getName() << " Destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	if (!isAlive() || !loseEnergy())
		return;
	std::cout << getName() << " 👋!" << std::endl;
}

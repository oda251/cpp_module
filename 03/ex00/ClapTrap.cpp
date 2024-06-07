#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "Default constructor called" << std::endl;
}
ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "Name constructor called" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &src) : _name(src._name), _hitPoints(src._hitPoints), _energyPoints(src._energyPoints), _attackDamage(src._attackDamage) {
    std::cout << "Copy constructor called" << std::endl;
}
ClapTrap::~ClapTrap() {
    std::cout << "Destructor called" << std::endl;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &src) {
    std::cout << "= called" << std::endl;
    _name = src._name;
    _hitPoints = src._hitPoints;
    _energyPoints = src._energyPoints;
    _attackDamage = src._attackDamage;
    return *this;
}

void ClapTrap::attack(const std::string &target) {
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount) {
    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount) {
    std::cout << "ClapTrap " << _name << " is repaired for " << amount << " points!" << std::endl;
}

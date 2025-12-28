#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) :
	ClapTrap("ScavTrap"),
	_gateKeeperMode(false)
{
	setMaxHitPoints(_defaultMaxHitPoints);
	setMaxEnergyPoints(_defaultMaxEnergyPoints);
	setHitPoints(_defaultMaxHitPoints);
	setEnergyPoints(_defaultMaxEnergyPoints);
	setAttackDamage(_defaultAttackDamage);
	std::cout << "ScavTrap default constructor" << std::endl;
}
ScavTrap::ScavTrap(std::string name) :
	ClapTrap(name),
	_gateKeeperMode(false)
{
	setMaxHitPoints(_defaultMaxHitPoints);
	setMaxEnergyPoints(_defaultMaxEnergyPoints);
	setHitPoints(_defaultMaxHitPoints);
	setEnergyPoints(_defaultMaxEnergyPoints);
	setAttackDamage(_defaultAttackDamage);
	std::cout << "ScavTrap constructor" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &src) :
	ClapTrap(src),
	_gateKeeperMode(src._gateKeeperMode)
{
	std::cout << "ScavTrap copy constructor" << std::endl;
}
ScavTrap::~ScavTrap(void) {
	std::cout << getName() << " destructor" << std::endl;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &src) {
	std::cout << "ScavTrap assignation operator" << std::endl;
	setName(src.getName());
	setMaxHitPoints(src.getMaxHitPoints());
	setMaxEnergyPoints(src.getMaxEnergyPoints());
	setHitPoints(src.getHitPoints());
	setEnergyPoints(src.getEnergyPoints());
	setAttackDamage(src.getAttackDamage());
	_gateKeeperMode = src._gateKeeperMode;
	return *this;
}

void ScavTrap::guardGate(void) {
	if (!isAlive() || !loseEnergy())
		return;
	if (_gateKeeperMode) {
		std::cout << getName() << " has exited gate keeper mode!" << std::endl;
		_gateKeeperMode = false;
	} else {
		std::cout << getName() << " has entered gate keeper mode!" << std::endl;
		_gateKeeperMode = true;
	}
}

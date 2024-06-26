#pragma once
#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		static const unsigned int _defaultMaxHitPoints = 100;
        static const unsigned int _defaultMaxEnergyPoints = 50;
		static const unsigned int _defaultAttackDamage = 20;
		bool _gateKeeperMode;

	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& other);
		~ScavTrap();
		ScavTrap& operator=(const ScavTrap& other);

		void guardGate();
};

#pragma once
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	private:
		static const unsigned int _maxHitPoints = 100;
		static const unsigned int _maxEnergyPoints = 100;
		static const unsigned int _defaultAttackDamage = 30;
	public:
		FragTrap();
		FragTrap(const std::string &name);
		FragTrap(const FragTrap &src);
		~FragTrap();
		FragTrap &operator=(const FragTrap &src);

		void highFivesGuys(void);
};

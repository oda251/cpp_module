#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
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
		void highFivesGuys(void);
};

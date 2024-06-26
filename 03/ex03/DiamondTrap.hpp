#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string _name;
		unsigned int _maxHitPoints;
		unsigned int _maxEnergyPoints;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;

	public:
		DiamondTrap();
		DiamondTrap(const std::string &name);
		DiamondTrap(const DiamondTrap &src);
		~DiamondTrap();
		
		std::string getName(void) const;
		unsigned int getHitPoints(void) const;
		unsigned int getEnergyPoints(void) const;
		unsigned int getAttackDamage(void) const;
		unsigned int getMaxHitPoints(void) const;
		unsigned int getMaxEnergyPoints(void) const;

		bool setName(const std::string &name);
		bool setHitPoints(unsigned int hitPoints);
		bool setEnergyPoints(unsigned int energyPoints);
		bool setAttackDamage(unsigned int attackDamage);
		bool setMaxHitPoints(unsigned int maxHitPoints);
		bool setMaxEnergyPoints(unsigned int maxEnergyPoints);

		void attack(const std::string &target);

		void whoAmI(void);
};

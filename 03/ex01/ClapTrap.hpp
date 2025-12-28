#pragma once
#include <iostream>

class ClapTrap
{
    private:
        std::string _name;
		unsigned int _maxHitPoints;
		unsigned int _maxEnergyPoints;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;
        static const unsigned int _defaultMaxHitPoints = 10;
        static const unsigned int _defaultMaxEnergyPoints = 10;
		static const unsigned int _defaultAttackDamage = 0;

    public:
        ClapTrap();
        ClapTrap(const std::string &name);
        ClapTrap(const ClapTrap &src);
        ~ClapTrap();
        ClapTrap &operator=(const ClapTrap &src);

        bool isAlive(void) const;
		bool loseEnergy(void);
		std::string getName(void) const;
		unsigned int getMaxHitPoints(void) const;
		unsigned int getMaxEnergyPoints(void) const;
		unsigned int getHitPoints(void) const;
		unsigned int getEnergyPoints(void) const;
		unsigned int getAttackDamage(void) const;
		bool setName(const std::string &name);
		bool setMaxHitPoints(unsigned int maxHitPoints);
		bool setMaxEnergyPoints(unsigned int maxEnergyPoints);
		bool setHitPoints(unsigned int hitPoints);
		bool setEnergyPoints(unsigned int energyPoints);
		bool setAttackDamage(unsigned int attackDamage);

        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};
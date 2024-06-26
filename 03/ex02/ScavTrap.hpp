#pragma once
#include <iostream>

class ScavTrap
{
    private:
        std::string _name;
		unsigned int _maxHitPoints;
		unsigned int _maxEnergyPoints;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;
		bool _gateKeeperMode;
        static const unsigned int _defaultMaxHitPoints = 100;
        static const unsigned int _defaultMaxEnergyPoints = 50;
		static const unsigned int _defaultAttackDamage = 20;

    public:
        ScavTrap();
        ScavTrap(const std::string &name);
        ScavTrap(const ScavTrap &src);
        ~ScavTrap();
        ScavTrap &operator=(const ScavTrap &src);

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
		void guardGate(void);
};
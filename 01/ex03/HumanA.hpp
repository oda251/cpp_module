#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanA {
	private:
		std::string	_name;
		Weapon		&_weapon;

	public:
		HumanA(std::string name, Weapon &weapon);
		void setWeapon(Weapon &weapon);
		void setName(std::string name);
		void attack(void);
};

#endif
#pragma once
#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria *_inventory[4];
	public:
		Character(std::string const & name);
		Character(Character const & src);
		Character & operator=(Character const & src);
		~Character();
		const std::string& getName() const;
		void setName(std::string const & name);
		AMateria *getMateria(int idx) const;
		void equip(AMateria* m);
		void unequip(int idx);
		void destroyEquipment(int idx);
		void use(int idx, ICharacter& target);
};

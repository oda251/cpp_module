#pragma once
#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
	protected:

	public:
		Ice();
		Ice(Ice const &other);
		Ice &operator=(Ice const &other);
		~Ice();
		std::string const &getType() const;
		void setType(std::string const &type);
		AMateria* clone() const;
		void use(ICharacter& target);
};

#pragma once
#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
	protected:

	public:
		Cure();
		Cure(Cure const &cure);
		Cure &operator=(Cure const &cure);
		~Cure();
		std::string const &getType() const;
		void setType(std::string const &type);
		AMateria* clone() const;
		void use(ICharacter& target);
};
